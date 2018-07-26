import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main (String[]args) throws IOException{
        BufferedReader br=new BufferedReader(
                new InputStreamReader(System.in));
        String[]colors=new String[3];
        colors=br.readLine().split(" ");
        String r="",g="",b="";
        r=Integer.toString(Integer.valueOf(colors[0]),13);
        g=Integer.toString(Integer.valueOf(colors[1]),13);
        b=Integer.toString(Integer.valueOf(colors[2]),13);
        r=r.toUpperCase();
        g=g.toUpperCase();
        b=b.toUpperCase();
        if(r.length()==1)
            r=0+r;
        if(g.length()==1)
            g=0+g;
        if(b.length()==1)
            b=0+b;
        System.out.println("#"+r+g+b);
    }
}
