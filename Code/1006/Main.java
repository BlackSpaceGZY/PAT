import java.util.Scanner;

public class Main {
    public static int compare(String s1,String s2){
        if(Integer.valueOf(s1.substring(0,2))>Integer.valueOf(s2.substring(0,2)))
                return 1;
        else if(Integer.valueOf(s1.substring(0,2))<Integer.valueOf(s2.substring(0,2)))
                return 0;
        else{
            if(Integer.valueOf(s1.substring(3,5))>Integer.valueOf(s2.substring(3,5)))
                    return 1;
            else if(Integer.valueOf(s1.substring(3,5))<Integer.valueOf(s2.substring(3,5)))
                    return 0;
            else{
                if(Integer.valueOf(s1.substring(7,9))>Integer.valueOf(s2.substring(7,9)))
                        return 1;
                else
                        return 0;
            }
        }
    }
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int M=sc.nextInt();
        String[] id=new String[M];
        String[] in=new String[M];
        String[] out=new String[M];
        for(int i=0;i<M;i++){
            id[i]=sc.next();
            in[i]=sc.next();
            out[i]=sc.next();
        }
        int min=0,max=0;
        for(int i=1;i<in.length;i++){
            if(compare(in[min],in[i])==1)
                min=i;
        }
        for(int i=1;i<out.length;i++){
            if(compare(out[max],out[i])==0)
                max=i;
        }
        System.out.println(id[min]+" "+id[max]);
    }
}
