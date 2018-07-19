import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] nums=new int[N];
        int l=0,r=N-1,max=0;
        int l1=0,sub=0;
        for(int i=0;i<N;i++){
            nums[i]=sc.nextInt();
            if (sub+nums[i]<0)
                sub=0;
            else{
                if(sub==0)
                    l1=i;
                sub+=nums[i];
                if(sub==0||sub>max){
                    max=sub;
                    l=l1;
                    r=i;
                }
            }
        }
        System.out.println(max+" "+nums[l]+" "+nums[r]);
    }
}
