
import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        double []num=new double[1001];
        int k1=sc.nextInt();
        while (k1-->0){
            num[sc.nextInt()]+=sc.nextDouble();
        }
        int k2=sc.nextInt();
        while (k2-->0){
            num[sc.nextInt()]+=sc.nextDouble();
        }
        String s="";
        int k=0;
        DecimalFormat df=new DecimalFormat("#.0");
        for(int i=num.length-1;i>=0;i--){
            if(num[i]!=0){
                s+=i+" "+df.format(num[i])+" ";
                k++;
            }
        }
        s=s.substring(0,s.length()-1);
        System.out.println(k+" "+s);
    }
}
