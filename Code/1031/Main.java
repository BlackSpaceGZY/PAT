import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[]args)throws Exception{
        BufferedReader br=new BufferedReader(
                new InputStreamReader(System.in)
        );
        String str=br.readLine();
        int length=(str.length()+2)%3==0?(str.length()+2)/3
                :(str.length()+2)%3==2?
                (str.length()+2)/3+2:(str.length()+2)/3+1;
        int length2=(str.length()+2-length)/2;
        for(int i=0;i<length2-1;i++){
            System.out.print(str.charAt(i));
            System.out.printf("%"+(length-2)+"s"," ");
            System.out.println(str.charAt(str.length()-1-i));
        }
        System.out.println(str.substring(length2-1,length+length2-1));
    }
}
