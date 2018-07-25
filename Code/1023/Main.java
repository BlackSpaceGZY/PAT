import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        String num=sc.next();
        int[]flag=new int[10];
        int j=0;
        String doubleNum="";
        for(int i=num.length()-1;i>=0;i--){
            int index=num.charAt(i)-'0';
            if(flag[index]==0)
                flag[index]=1;
            doubleNum=(index*2+j)%10+doubleNum;
            if(index*2+j>=10)
                j=1;
            else
                j=0;
        }
        if(j==1)
            doubleNum=1+doubleNum;
        int i=0;
        for(;i<doubleNum.length();i++){
            if(flag[doubleNum.charAt(i)-'0']==0||j==1){
                System.out.println("No");
                break;
            }
        }
        if(i==doubleNum.length())
            System.out.println("Yes");
        System.out.println(doubleNum);
    }
}
