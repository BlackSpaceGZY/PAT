import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static int find(String num,String[]id){
        for(int i=0;i<id.length;i++)
            if(num.equals(id[i]))
                return i;
        return -1;

    }
    public static int[] sort(int[][]score,int index){
        int best=Integer.MAX_VALUE;
        int bm=0;
        for(int j=0;j<score[0].length;j++){
            int grade=score[index][j];
            int now=1;
            List<Integer>list=new ArrayList<>();
            for(int i=0;i<score[0].length;i++){
                if(i==index)
                    continue;
                if(grade<score[i][j]&&!list.contains(score[i][j])) {
                    now++;
                    list.add(score[i][j]);
                }
            }
            if(now<best) {
                best = now;
                bm=j;
            }
            now=1;
        }
        int[] best1=new int[2];
        best1[0]=bm;
        best1[1]=best;
        return best1;
    }
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int M=sc.nextInt();
        String[] id=new String[N];
        int[][]score=new int[N][4];
        for(int i=0;i<N;i++){
            id[i]=sc.next();
            score[i][1]=sc.nextInt();
            score[i][2]=sc.nextInt();
            score[i][3]=sc.nextInt();
            score[i][0]=(int)Math.round((double)(score[i][1]+score[i][2]+score[i][3])/3);
        }
        String[] check=new String[M];
        for(int i=0;i<M;i++)
            check[i]=sc.next();
        for(int i=0;i<M;i++){
            int index=find(check[i],id);
            if(index==-1)
                System.out.println("N/A");
            else{
                int[] best=sort(score,index);
                switch (best[0]){
                    case 0:
                        System.out.println(best[1]+" A");
                        break;
                    case 1:
                        System.out.println(best[1]+" C");
                        break;
                    case 2:
                        System.out.println(best[1]+" M");
                        break;
                    case 3:
                        System.out.println(best[1]+" E");
                        break;
                }
            }
        }
    }
}
