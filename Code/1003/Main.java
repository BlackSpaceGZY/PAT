import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    int minLength=0;
    int maxNumber=0;
    int count=0;
    public void find(int C1,int C2,int[]secure,int[][]road,List<Integer>list
            ,int length,int number){
        if(C1==C2){
            length+=road[C1][C2];
            number+=secure[C1];
            if(minLength==0){
                minLength=length;
                maxNumber=number;
                count=1;
            }
            else{
                if(minLength<length)
                    return;
                else if(minLength==length) {
                    maxNumber = maxNumber > number ? maxNumber : number;
                    count++;
                }
                else{
                    minLength=length;
                    maxNumber=number;
                    count=1;
                }
            }
            return;
        }
        for(int i=0;i<road[C1].length;i++){
            if(road[C1][i]==0||i==C1||list.contains(i))
                continue;
            list.add(i);
            length+=road[C1][i];
            number+=secure[C1];
            find(i,C2,secure,road,list,length,number);
            length-=road[C1][i];
            number-=secure[C1];
            list.remove(list.size()-1);
        }
    }
    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int M=sc.nextInt();
        int C1=sc.nextInt();
        int C2=sc.nextInt();
        int[] secure=new int[N];
        for(int i=0;i<N;i++)
            secure[i]=sc.nextInt();
        int[][] road=new int[N][N];
        for(int i=0;i<M;i++)
            road[sc.nextInt()][sc.nextInt()]=sc.nextInt();
        Main m=new Main();
        m.find(C1,C2,secure,road,new ArrayList<>(),0,0);
        System.out.print(m.count+" "+m.maxNumber);
    }
}
