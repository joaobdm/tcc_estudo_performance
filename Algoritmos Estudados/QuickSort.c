#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int number[], int first, int last) {
   int i, j, pivot, temp;

   if (first < last) {
      pivot = first;
      i = first;
      j = last;

      while (i < j) {
         while (number[i] <= number[pivot] && i < last)
            i++;
         while (number[j] > number[pivot])
            j--;
         if (i < j) {
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
         }
      }

      temp = number[pivot];
      number[pivot] = number[j];
      number[j] = temp;
      quicksort(number, first, j - 1);
      quicksort(number, j + 1, last);
   }
}

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
    quicksort(number, 0, size - 1);
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
