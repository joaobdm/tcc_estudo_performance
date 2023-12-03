import time

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break

if __name__ == '__main__':
    with open('input.txt', 'r') as file:
        arr = [int(line.strip()) for line in file]

    print('Original Array:', arr[:50] + ["..."] + arr[-50:])

    start_time = time.time()
    bubble_sort(arr)
    end_time = time.time()

    print('Sorted array:', arr[:50] + ["..."] + arr[-50:])
    print('Time taken:', end_time - start_time, 'seconds')
