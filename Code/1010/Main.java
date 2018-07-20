import java.util.Scanner;

public class Main {
    public static long transform(String N,int radix){
        long num=0;
        int j=0;
        for(int i=N.length()-1;i>=0;i--){
            if(48<=N.charAt(i)&&N.charAt(i)<=57)
                num+=(long)Math.pow(radix,j)*(N.charAt(i)-'0');
            else
                num+=(long)Math.pow(radix,j)*(N.charAt(i)-'a'+10);
            j++;
        }
        return num;
    }
    public static int compare(long N1,String N2){
        int i=find(N2);
        for(;i<100;i++){
            if (N1==transform(N2,i)){
                return i;
            }
        }
        return -1;
    }
    public static int find(String N){
        int num=0;
        for(int i=0;i<N.length();i++){
            if(N.charAt(i)>num)
                num=N.charAt(i);
        }
        if(num<=57)
            return num-'0'+1;
        else
            return num-'a'+11;
    }
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int radix1=0,radix2=0;
        long n1=0,n2=0;
        String N1=sc.next();
        String N2=sc.next();
        if(sc.nextInt()==1) {
            radix1 = sc.nextInt();
            n1=transform(N1,radix1);
            radix2 = compare(n1, N2);
            if(radix2==-1)
                System.out.println("Impossible");
            else
                System.out.println(radix2);
        }
        else {
            radix2 = sc.nextInt();
            n2=transform(N2,radix2);
            radix1 = compare(n2, N1);
            if(radix1==-1)
                System.out.println("Impossible");
            else
                System.out.println(radix1);
        }
    }
}
