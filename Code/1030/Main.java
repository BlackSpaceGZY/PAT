import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static List<Integer>list;
    public static int min=Integer.MAX_VALUE;
    public static int minLength=Integer.MAX_VALUE;
    public static void find(int[][]roads,int[][]costs,int length,int cost,int i,int j,
                            List<Integer>list1){
        if(i==j){
            if(length<minLength){
                list = new ArrayList<>(list1);
                min=cost;
                minLength=length;
            }
            else if(length==minLength) {
                if (cost < min) {
                    list = new ArrayList<>(list1);
                    min = cost;
                }
            }
            return;
        }
        for(int k=0;k<roads.length;k++){
            if(roads[i][k]==0||list1.contains(k)||k==i)
                continue;
            list1.add(k);
            cost+=costs[i][k];
            length+=roads[i][k];
            find(roads,costs,length,cost,k,j,list1);
            list1.remove(new Integer(k));
            cost-=costs[i][k];
            length-=roads[i][k];
        }

    }
    public static void main(String[]args)throws IOException{
        BufferedReader br=new BufferedReader(
                new InputStreamReader(System.in)
        );
        String[]line1=br.readLine().split(" ");
        int N=Integer.valueOf(line1[0]);
        int[][] costs=new int[N][N];
        int[][]roads=new int[N][N];
        for(int i=0;i<Integer.valueOf(line1[1]);i++){
            String[] line=br.readLine().split(" ");
            roads[Integer.valueOf(line[0])][Integer.valueOf(line[1])]=
            roads[Integer.valueOf(line[1])][Integer.valueOf(line[0])]
                    =Integer.valueOf(line[2]);
            costs[Integer.valueOf(line[0])][Integer.valueOf(line[1])]=
            costs[Integer.valueOf(line[1])][Integer.valueOf(line[0])]
                    =Integer.valueOf(line[3]);
        }
        find(roads,costs,0,0,Integer.valueOf(line1[2]),Integer.valueOf(line1[3]),
                new ArrayList<>());
        System.out.print(Integer.valueOf(line1[2])+" ");
        for(int i:list)
            System.out.print(i+" ");
        System.out.print(minLength+" "+min);

    }
}