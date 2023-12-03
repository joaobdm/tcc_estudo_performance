import time

def partition(arr, low, high):
    i = low - 1
    pivot = arr[high]

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

if __name__ == '__main__':
    with open('input.txt', 'r') as file:
        arr = [int(line.strip()) for line in file]

    n = len(arr)
    start_time = time.time()
    quick_sort(arr, 0, n - 1)
    end_time = time.time()

    print("Sorted array is:", arr[:50] + ["..."] + arr[-50:])
    print("Time taken:", end_time - start_time, "seconds")
