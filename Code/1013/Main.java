import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    List<Integer>temp=new ArrayList<>();
    public List<Integer> help(int[][]roads, int road){
        List<Integer>connect=new ArrayList<>();
        for(int i=1;i<roads[0].length;i++){
            if(roads[road][i]!=0)
                connect.add(i);
        }
        return connect;
    }
    public void repair(int[][]roads,List<Integer>connect,int warroad,int index){
        for(int j=index+1;j<connect.size();j++){
            if(roads[connect.get(index)][connect.get(j)]==1&&connect.get(j)!=warroad){
                temp.add(connect.get(j));
                repair(roads,connect,warroad,j);
            }
        }
    }
    public int repaired(int[][]roads,List<Integer>connect,int warroad){
        int n=-1;
        while (connect.size()!=0) {
            temp.add(connect.get(0));
            repair(roads, connect, warroad,0);
            connect.removeAll(temp);
            temp=new ArrayList<>();
            n++;
        }
        return n;
    }
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int M=sc.nextInt();
        int K=sc.nextInt();
        int [][]roads=new int[N+1][N+1];
        int []check=new int[K];
        while (M-->0){
            int n1=sc.nextInt();
            int n2=sc.nextInt();
            roads[n1][n2]=roads[n2][n1]=1;
        }
        for(int i=0;i<K;i++)
            check[i]=sc.nextInt();
        Main main=new Main();
        int []r=new int[check.length];
        for(int i=0;i<check.length;i++) {
            List<Integer> connect = main.help(roads, check[i]);
            r[i]=main.repaired(roads,connect,i+1);
        }
        for(int i:r)
            System.out.println(i);

    }
}
