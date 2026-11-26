/* Client management using fixed-size, directly addressed binary records.
 * Educational implementation; use fictional client data only.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define MIN_ID 10000
#define MAX_ID 99999
#define DATA_FILE "clients.dat"
#define RECORD_SIZE 66L

typedef struct {
    char name[41];
    char tax_id[13];
    char phone[13];
} Client;

/* Disk format: active byte, 40 name bytes, 12 tax bytes, 12 phone
 * bytes, reserved byte. No compiler-dependent structure padding. */
static int read_line(const char *prompt, char *out, size_t size)
{
    for (;;) {
        printf("%s", prompt);
        fflush(stdout);
        if (!fgets(out, (int)size, stdin)) return 0;
        size_t n = strlen(out);
        if (n && out[n - 1] == '\n') {
            out[n - 1] = '\0';
            return 1;
        }
        int ch = getchar();
        if (ch == '\n' || ch == EOF) return 1;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        puts("Input too long. Try again.");
    }
}

static int read_number(const char *prompt, long min, long max, long *value)
{
    char line[80];
    while (read_line(prompt, line, sizeof line)) {
        char *end;
        errno = 0;
        long n = strtol(line, &end, 10);
        if (end != line && errno == 0) {
            while (isspace((unsigned char)*end)) ++end;
            if (!*end && n >= min && n <= max) {
                *value = n;
                return 1;
            }
        }
        printf("Enter a number between %ld and %ld.\n", min, max);
    }
    return 0;
}

static int read_field(const char *prompt, char *out, size_t size)
{
    while (read_line(prompt, out, size)) {
        if (out[strspn(out, " \t\r")] != '\0') return 1;
        puts("Field cannot be empty.");
    }
    return 0;
}

static int read_client(Client *c)
{
    memset(c, 0, sizeof *c);
    return read_field("Full name: ", c->name, sizeof c->name) &&
           read_field("Tax ID: ", c->tax_id, sizeof c->tax_id) &&
           read_field("Phone: ", c->phone, sizeof c->phone);
}

static int confirm_action(void)
{
    char line[16];
    while (read_line("Confirm (y/n): ", line, sizeof line)) {
        if (!strcmp(line, "y") || !strcmp(line, "Y")) return 1;
        if (!strcmp(line, "n") || !strcmp(line, "N")) return 0;
    }
    return 0;
}

static FILE *open_file(void)
{
    FILE *file = fopen(DATA_FILE, "rb+");
    if (!file && errno == ENOENT) file = fopen(DATA_FILE, "wb+x");
    return file;
}

static int seek_record(FILE *file, long id)
{
    if (id < MIN_ID || id > MAX_ID) return 0;
    return fseek(file, (id - MIN_ID) * RECORD_SIZE, SEEK_SET) == 0;
}

/* Return 1 for an active record, 0 for an empty slot, -1 on error. */
static int find_record(FILE *file, long id, Client *c)
{
    unsigned char raw[RECORD_SIZE];
    if (!seek_record(file, id)) return -1;
    size_t n = fread(raw, 1, sizeof raw, file);
    if (ferror(file)) return -1;
    if (n == 0 && feof(file)) return 0;
    if (n != sizeof raw || raw[0] > 1 || raw[65] != 0) return -1;
    if (!raw[0]) return 0;
    memset(c, 0, sizeof *c);
    memcpy(c->name, raw + 1, 40);
    memcpy(c->tax_id, raw + 41, 12);
    memcpy(c->phone, raw + 53, 12);
    return 1;
}

static int write_record(FILE *file, long id, const Client *c)
{
    unsigned char raw[RECORD_SIZE] = {0};
    if (c) {
        raw[0] = 1;
        memcpy(raw + 1, c->name, strlen(c->name));
        memcpy(raw + 41, c->tax_id, strlen(c->tax_id));
        memcpy(raw + 53, c->phone, strlen(c->phone));
    }
    return seek_record(file, id) &&
           fwrite(raw, 1, sizeof raw, file) == sizeof raw &&
           fflush(file) == 0;
}

static void print_client(long id, const Client *c)
{
    printf("%05ld  %-40s  %-12s  %-12s\n", id, c->name, c->tax_id, c->phone);
}

static int list_records(FILE *file, long first, long last)
{
    Client c;
    long count = 0;
    printf("%-5s  %-40s  %-12s  %-12s\n", "ID", "Name", "Tax ID", "Phone");
    for (long id = first; id <= last; ++id) {
        int result = find_record(file, id, &c);
        if (result < 0) return 0;
        if (result == 1) {
            print_client(id, &c);
            ++count;
        } else if (feof(file)) break;
    }
    printf("Total: %ld\n", count);
    return 1;
}

static int manage_record(FILE *file, long choice)
{
    long id;
    Client c;
    if (!read_number("Client ID: ", MIN_ID, MAX_ID, &id)) return 1;
    int result = find_record(file, id, &c);
    if (result < 0) return 0;
    if (choice == 1 && result == 1) {
        puts("Client already exists.");
        return 1;
    }
    if (choice != 1 && result == 0) {
        puts("Client not found.");
        return 1;
    }
    if (result == 1) print_client(id, &c);
    if (choice == 2) return 1;
    if (choice != 4 && !read_client(&c)) return 1;
    if (!confirm_action()) {
        puts("Operation cancelled.");
        return 1;
    }
    if (!write_record(file, id, choice == 4 ? NULL : &c)) return 0;
    puts(choice == 4 ? "Client deleted." : "Client saved.");
    return 1;
}

int main(void)
{
    FILE *file = open_file();
    if (!file) {
        perror(DATA_FILE);
        return EXIT_FAILURE;
    }
    /* Reject incomplete or oversized files before processing records. */
    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return EXIT_FAILURE;
    }
    long length = ftell(file);
    if (length < 0 || length % RECORD_SIZE != 0 ||
        length > (MAX_ID - MIN_ID + 1L) * RECORD_SIZE) {
        fprintf(stderr, "Invalid client file format.\n");
        fclose(file);
        return EXIT_FAILURE;
    }
    int success = 1;
    long choice;
    for (;;) {
        puts("\n=== CLIENT MANAGEMENT SYSTEM ===\n"
             "1. Add client\n2. View client\n3. Update client\n"
             "4. Delete client\n5. List all clients\n"
             "6. List clients by ID range\n0. Exit");
        if (!read_number("Select an option: ", 0, 6, &choice) || choice == 0) break;
        if (choice <= 4) success = manage_record(file, choice);
        else if (choice == 5) success = list_records(file, MIN_ID, MAX_ID);
        else {
            long first, last;
            if (!read_number("From ID: ", MIN_ID, MAX_ID, &first) ||
                !read_number("To ID: ", first, MAX_ID, &last)) break;
            success = list_records(file, first, last);
        }
        if (!success) {
            fprintf(stderr, "Client file I/O or format error.\n");
            break;
        }
    }
    if (fclose(file) != 0) success = 0;
    return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
