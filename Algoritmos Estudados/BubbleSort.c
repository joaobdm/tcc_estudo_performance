#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubblesort(int *a, int size) {
    int swapped;
    for (int i = 0; i < size; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
    return 0;
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
    int *a = (int *)malloc(size * sizeof(int));
    if (a == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    while (fscanf(file, "%d", &a[index]) == 1) {
        index++;
    }
    fclose(file);

    clock_t start = clock();
    bubblesort(a, size);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken for sorting: %f seconds\n", time_taken);

    printf("\nFirst 50 elements:\n");
    for (int i = 0; i < 50 && i < size; i++) {
        printf("%d ", a[i]);
    }

    printf("\n\nLast 50 elements:\n");
    for (int i = (size > 50 ? size - 50 : 0); i < size; i++) {
        printf("%d ", a[i]);
    }

    free(a);
    return 0;
}
