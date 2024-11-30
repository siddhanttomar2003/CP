import java.util.Scanner;

public class MaximumSubarraySum {
    public static int maxCrossingSum(int[] arr, int low, int mid, int high) {

        int leftSum = Integer.MIN_VALUE;
        int sum = 0;
        for (int i = mid; i >= low; i--) {
            sum += arr[i];
            if (sum > leftSum) {
                leftSum = sum;
            }
        }
        int rightSum = Integer.MIN_VALUE;
        sum = 0;
        for (int i = mid + 1; i <= high; i++) {
            sum += arr[i];
            if (sum > rightSum) {
                rightSum = sum;
            }
        }

        return leftSum + rightSum;
    }

    public static int maxSubarraySum(int[] arr, int low, int high) {
    
        if (low == high) {
            return arr[low];
        }

        int mid = (low + high) / 2;

      
        return Math.max(
                Math.max(maxSubarraySum(arr, low, mid), maxSubarraySum(arr, mid + 1, high)),
                maxCrossingSum(arr, low, mid, high)
        );
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = scanner.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        int maxSum = maxSubarraySum(arr, 0, n - 1);
        System.out.println("The maximum subarray sum is: " + maxSum);

        scanner.close();
    }
}
