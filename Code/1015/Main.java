import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static boolean isPrime(int N) {
        if(N==1)
            return false;
        for (int i = 2; i <= Math.sqrt(N); i++) {
            if (N % i == 0)
                return false;
        }
        return true;
    }

    public static String isReversible(int N, int D) {
        if (isPrime(N) == false)
            return "No";
        else{
            int N2=reverse(N,D);
            if (isPrime(N2)==false)
                return "No";
            else
                return "Yes";
        }
    }

    public static int reverse(int N, int D) {
        String r=Integer.toString(N,D);
        String rs="";
        for(int i=r.length()-1;i>=0;i--)
            rs+=r.charAt(i);
        return Integer.parseInt(rs,D);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<String>list=new ArrayList<>();
        while (sc.hasNext()) {
            int N = sc.nextInt();
            if (N < 0)
                break;
            int D = sc.nextInt();
            list.add(isReversible(N,D));
        }
        for(String s:list)
            System.out.println(s);
    }
}