import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int seconds=N*5;
        int former=0;
        for(int i=0;i<N;i++){
            int now=sc.nextInt();
            if(now-former>0)
                seconds+=6*(now-former);
            else
                seconds+=4*(former-now);
            former=now;
        }
        System.out.println(seconds);
    }
}
