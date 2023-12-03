import java.io.*;
import java.util.*;

public class InsertionSort {
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
        insertionSort(arr);
        long endTime = System.nanoTime();

        System.out.println("\nTempo de execução: " + (endTime - startTime) + " ns");

        System.out.println("\nPrimeiros 50 elementos:");
        for (int i = 0; i < 50 && i < arr.length; i++)
            System.out.print(arr[i] + " ");

        System.out.println("\n\nÚltimos 50 elementos:");
        for (int i = Math.max(0, arr.length - 50); i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }

    static void insertionSort(int arr[]) {
        int len = arr.length, tmp, j;
        for (int i = 1; i < len; i++) {
            tmp = arr[i];
            for (j = i; j > 0 && arr[j - 1] > tmp; j--) {
                arr[j] = arr[j - 1];
            }
            arr[j] = tmp;
        }
    }
}
