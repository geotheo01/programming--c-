// Random Printable ASCII Array: fills an array with printable ASCII characters (32-126)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_random_chars(char arr[], int N)
{
    for(int i = 0; i < N; i++)
    {
        arr[i] = (char)(rand() % 95 + 32); // Random printable ASCII character (32–126)
    }
}

int main(void)
{
    srand(time(NULL));

    int N = 10;
    char arr[N];

    fill_random_chars(arr, N);

    printf("Random characters: ");

    for(int i = 0; i < N; i++)
    {
        printf("%c ", arr[i]);
    }

    printf("\n");

    return 0;
}
