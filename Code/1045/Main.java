import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[]args)throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int m=Integer.valueOf(br.readLine());
        String[]s1=br.readLine().split(" ");
        int N=Integer.valueOf(s1[0]);
        int[]hashTable=new int[201];
        for(int i=1;i<=N;i++)
            hashTable[Integer.valueOf(s1[i])]=i;
        String []line2=br.readLine().split(" ");
        int l=Integer.valueOf(line2[0]);
        int[]stripe=new int[l];
        int num=0;
        for(int i=0;i<l;i++) {
            int a=Integer.valueOf(line2[i+1]);
            if(hashTable[a]>0)
                stripe[num++]=hashTable[a];
        }
        int ans=-1;
        int[]dp=new int[num];
        for(int i=0;i<num;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(stripe[j]<=stripe[i]&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            ans=Math.max(ans,dp[i]);
        }
        System.out.println(ans);
    }
}
