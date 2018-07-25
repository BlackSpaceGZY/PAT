import java.util.Scanner;

public class Main {
    public static String reverseAdd(String N){
        int j=0;
        String s="";
        for(int i=N.length()-1;i>=0;i--){
            s=(N.charAt(i)-'0'+N.charAt(N.length()-1-i)-'0'+j)%10+s;
            if(N.charAt(i)-'0'+N.charAt(N.length()-1-i)-'0'+j>=10)
                j=1;
            else j=0;
        }
        if(j==1)
            s=1+s;
        return s;
    }
    public static boolean isPalindromic(String N){
        int i=0,j=N.length()-1;
        while (i<j){
            if(N.charAt(i)!=N.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        String N=sc.next();
        int K=sc.nextInt();
        int i=0;
        for(;i<K;i++){
            if(isPalindromic(N))
                break;
            N=reverseAdd(N);
        }
        System.out.println(N);
        System.out.println(i);
    }
}
