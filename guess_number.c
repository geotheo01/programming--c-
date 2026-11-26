// Number Guessing Game: interactive CLI game with random generator and 7 attempts limit

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int secret;
    int guess;
    int attempts = 7;
    int i;

    srand(time(NULL));
    secret = rand() % 100 + 1;

    printf("Game: Guess the Number!\n");
    printf("The secret number is between 1 and 100.\n");
    printf("You have 7 attempts.\n\n");

    for(i = 1; i <= attempts; i++)
    {
        printf("Attempt %d: Enter number: ", i);
        scanf("%d", &guess);

        if(guess == secret)
        {
            printf("Congratulations! You found the number %d!\n", secret);
            return 0;
        }

        printf("Remaining attempts: %d\n\n", attempts - i);
    }

    printf("Game over! The correct number was %d.\n", secret);

    return 0;
}
