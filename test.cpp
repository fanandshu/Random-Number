#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define TOTAL 44

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Create an array to keep track of used numbers
    int used[TOTAL] = {0};
    FILE *file=fopen("D:\\codes\\used.txt", "r");
    int i=0;
    while (!feof(file))
    {
        fscanf(file,"%d",&used[i]);
        i++;
    }
    fclose(file);
    
    // Check if all numbers have been used
    int allUsed = 1;
    for (int i = 1; i <= TOTAL; i++) {
        if (!used[i - 1]) {
            allUsed = 0;
            break;
        }
    }

    if (allUsed) {
        // If all numbers are used, delete the contents of "used.txt"
        FILE *file = fopen("D:\\codes\\used.txt", "w");
        if (file != NULL) {
            fclose(file);
            printf("All numbers used. 'used.txt' is cleared.\n");
        } else {
            perror("Error opening 'used.txt' for writing");
        }
    } else {
        // Generate and print a random unused number
        int randomNum;
        int i;
        do {
            randomNum = rand() % TOTAL + 1;
            for( i=0 ; used[i] != 0 ; i++)
            {
                if(used[i]==randomNum)
                {
                    break;
                }
            }
        } while (used[i] != 0);

        used[randomNum - 1] = 1;
        printf("Random number: %d\n", randomNum);

        // Store the used number in "used.txt"
        FILE *file = fopen("D:\\codes\\used.txt", "a");
        if (file != NULL) {
            fprintf(file, "%d\n", randomNum);
            fclose(file);
        } else {
            perror("Error opening 'used.txt' for appending");
        }
    }
    system("pause");
    return 0;
}
