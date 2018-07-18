import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        if(Math.abs(a+b)<1000)
            System.out.println(a+b);
        else {
            String s = a + b + "";
            String str="";
            if(a+b<0){
                s=s.substring(1);
            }
            for(int i=s.length()-1;i>=0;i--) {
                str = s.charAt(i)+str;
                if((s.length()-i)%3==0&&i!=0)
                    str=","+str;
            }
            if(a+b<0)
                str="-"+str;
            System.out.println(str);
        }
    }
}
