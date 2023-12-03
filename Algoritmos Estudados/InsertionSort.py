import time

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

if __name__ == '__main__':
    with open('input.txt', 'r') as file:
        arr = [int(line.strip()) for line in file]

    start_time = time.time()
    insertion_sort(arr)
    end_time = time.time()

    print("Sorted array is:", arr[:50] + ["..."] + arr[-50:])
    print("Time taken:", end_time - start_time, "seconds")
