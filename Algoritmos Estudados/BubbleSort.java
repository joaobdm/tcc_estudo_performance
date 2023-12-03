import java.io.*;
import java.util.*;

public class BubbleSort {
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
        bubbleSort(arr);
        long endTime = System.nanoTime();

        System.out.println("\nTempo de execução: " + (endTime - startTime) + " ns");

        System.out.println("\nPrimeiros 50 elementos:");
        for (int i = 0; i < 50 && i < arr.length; i++)
            System.out.print(arr[i] + " ");

        System.out.println("\n\nÚltimos 50 elementos:");
        for (int i = Math.max(0, arr.length - 50); i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }

    static void bubbleSort(int arr[]) {
        int len = arr.length, tmp;
        boolean flag;
        for (int i = 0; i < len; i++) {
            flag = false;
            for (int j = 0; j < len - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                    flag = true;
                }
            }
            if (!flag)
                break;
        }
    }
}
