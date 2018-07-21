import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        double max=1;
        String s="";
        for(int i=0;i<3;i++){
            double n1=sc.nextDouble();
            double n2=sc.nextDouble();
            double n3=sc.nextDouble();
            if(n1>n2&&n1>n3) {
                max *= n1;
                s+="W ";
            }
            else if(n2>n1&&n2>n3) {
                max *= n2;
                s+="T ";
            }
            else{
                max*=n3;
                s+="L ";
            }
        }
        DecimalFormat df=new DecimalFormat("#.00");
        System.out.println(s+df.format((max*0.65-1)*2));

    }
}
