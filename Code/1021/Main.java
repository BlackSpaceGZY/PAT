import java.util.*;

public class Main {
    List<Integer>root=new ArrayList<>();
    List<Integer>tree=new ArrayList<>();
    public  void find(int[][]trees,int i){
        boolean flag=true;
        for(int j=i+1;j<trees.length;j++){
            if(trees[i][j]==1){
                flag=false;
                if(tree.contains(new Integer(j))){
                    System.out.println("Error: "+tree.size()+" components");
                    System.exit(1);
                }
                tree.add(j);
                find(trees,j);
            }
        }
        if(flag==true)
            this.root.add(i);

    }
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[][]trees=new int[N+1][N+1];
        while (N-->1)
            trees[sc.nextInt()][sc.nextInt()]=1;
        Main main=new Main();
        for(int i=1;i<trees.length;i++){
            if(main.tree.contains(new Integer(i)))
                continue;
            else{
                main.tree=new ArrayList<>();
                main.find(trees,i);
            }
        }
        Collections.sort(main.root);
        for(int i:main.root)
            System.out.println(i);
    }
}
