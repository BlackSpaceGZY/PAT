import java.util.Scanner;

public class Main {
    public static void main(String[]args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int b = sc.nextInt();
            int pos = 0;
            int[] digit = new int[100];
            while (N != 0) {
                digit[pos] = N % b;
                N /= b;
                pos++;
            }
            int i = 0, j = pos-1;
            while (i < j) {
                if (digit[i] == digit[j]) {
                    i++;
                    j--;
                } else
                    break;
            }
            if (i == j || i - j == 1) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
            for (int k = pos - 1; k > 0; k--)
                System.out.print(digit[k] + " ");
            System.out.println(digit[0]);
        }
}
