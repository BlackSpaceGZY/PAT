import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String number = sc.next();
        String s="";
        int digit=0;
        for(int i=0;i<number.length();i++){
            digit+=number.charAt(i)-'0';
        }
        if(digit==0)
            s=" zero";
        while (digit!=0){
            switch (digit%10) {
                case 0:
                    s=" zero"+s;
                    break;
                case 1:
                    s=" one"+s;
                    break;
                case 2:
                    s=" two"+s;
                    break;
                case 3:
                    s=" three"+s;
                    break;
                case 4:
                    s=" four"+s;
                    break;
                case 5:
                    s=" five"+s;
                    break;
                case 6:
                    s=" six"+s;
                    break;
                case 7:
                    s=" seven"+s;
                    break;
                case 8:
                    s=" eight"+s;
                    break;
                case 9:
                    s=" nine"+s;
                    break;
            }
            digit/=10;
        }
        s=s.substring(1);
        System.out.println(s);
    }
}
