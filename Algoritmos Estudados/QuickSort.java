import java.io.*;
import java.util.*;

public class QuickSort {
    public static void main(String args[]) throws IOException {
        File file = new File("input.txt");
        BufferedReader br = new BufferedReader(new FileReader(file));

        List<Integer> list = new ArrayList<>();
        String line;
        while ((line = br.readLine()) != null) {
            list.add(Integer.parseInt(line.trim()));
        }

        int n = list.size();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = list.get(i);
        }

        long startTime = System.nanoTime();
        quickSort(arr, 0, n - 1);
        long endTime = System.nanoTime();

        System.out.println("\nTempo de execução: " + (endTime - startTime) + " ns");

        System.out.println("\nPrimeiros 50 elementos:");
        for (int i = 0; i < 50 && i < arr.length; i++)
            System.out.print(arr[i] + " ");

        System.out.println("\n\nÚltimos 50 elementos:");
        for (int i = Math.max(0, arr.length - 50); i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }

    static void quickSort(int arr[], int lower, int upper) {
        if (lower >= upper)
            return;
        int p = partition(arr, lower, upper);
        quickSort(arr, lower, p - 1);
        quickSort(arr, p + 1, upper);
    }

    private static int partition(int arr[], int lower, int upper) {
        int pivot = arr[upper];
        int j = lower;
        int tmp;
        for (int i = lower; i <= upper; i++) {
            if (arr[i] < pivot) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                j++;
            }
        }
        tmp = arr[upper];
        arr[upper] = arr[j];
        arr[j] = tmp;

        return j;
    }
}
