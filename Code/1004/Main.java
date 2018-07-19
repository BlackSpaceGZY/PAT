import java.util.Scanner;

public class Main {
    int[]count;
    int row=0;
    public void find(int[][]picture,int i,int row){
        boolean flag=false;
        for(int j=i+1;j<picture.length;j++){
            if(picture[i][j]==1){
                flag=true;
                find(picture,j,row+1);
            }
        }
        this.row=Math.max(this.row,row);
        if(flag==false)
            this.count[row]+=1;
    }
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int M=sc.nextInt();
        int[][]picture=new int[N+1][N+1];
        for(int i=0;i<M;i++){
            int index=sc.nextInt();
            int num=sc.nextInt();
            for(int j=1;j<=num;j++)
                picture[index][sc.nextInt()]=1;
        }
        Main m=new Main();
        m.count=new int[N+1];
        m.find(picture,1,1);
        for(int i=1;i<=m.row;i++) {
            if(i==m.row)
                System.out.print(m.count[i]);
            else
            System.out.print(m.count[i] + " ");
        }
    }
}
