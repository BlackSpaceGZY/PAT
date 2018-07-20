import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        double[]A=new double[1001];
        double[]B=new double[1001];
        double[]C=new double[2002];
        int N1=sc.nextInt();
        for(int i=0;i<N1;i++)
            A[sc.nextInt()]=sc.nextDouble();
        int N2=sc.nextInt();
        int n2=N2;
        for(int i=0;i<N2;i++)
            B[sc.nextInt()]=sc.nextDouble();
        for(int i=0;i<A.length;i++) {
            if(N1==0)
                break;
            if(A[i]==0)
                continue;
            for (int j = 0; j < B.length; j++) {
                if(N2==0) {
                    N2=n2;
                    break;
                }
                if(B[j]==0)
                    continue;
                else {
                    C[i + j] += A[i] * B[j];
                    N2--;
                }
            }
            N1--;
        }
        String s="";
        int count=0;
        DecimalFormat df=new DecimalFormat("#.0");
        for(int i=0;i<C.length;i++){
            if(C[i]!=0) {
                s = " " + i + " " + (double)Math.round(C[i]*10)/10+s;
                count++;
            }
        }
        if(s.length()>0)
        s=s.substring(1);
        System.out.println(count+" "+s);
    }
}
