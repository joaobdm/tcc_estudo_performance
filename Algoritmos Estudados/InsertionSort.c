#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int size = 0, value, index = 0;
    while (fscanf(file, "%d", &value) == 1) {
        size++;
    }

    fseek(file, 0, SEEK_SET);
    int *number = (int *)malloc(size * sizeof(int));
    if (number == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    while (fscanf(file, "%d", &number[index]) == 1) {
        index++;
    }
    fclose(file);

    clock_t start = clock();
   
    for (int i = 1; i < size; i++) {
        int temp = number[i], j = i - 1;
        while (j >= 0 && number[j] > temp) {
            number[j + 1] = number[j];
            j--;
        }
        number[j + 1] = temp;
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken for sorting: %f seconds\n", time_taken);

    printf("\nFirst 50 elements:\n");
    for (int i = 0; i < 50 && i < size; i++) {
        printf("%d ", number[i]);
    }

    printf("\n\nLast 50 elements:\n");
    for (int i = (size > 50 ? size - 50 : 0); i < size; i++) {
        printf("%d ", number[i]);
    }

    free(number);
    return 0;
}
