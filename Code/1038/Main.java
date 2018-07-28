import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static BigInteger min=new BigInteger("0");
    public static void help(String[] line,String s,List<String>list){
        if(list.size()==line.length-1&&list.size()!=0){
            BigInteger bigInteger=new BigInteger(s);
            if(min.compareTo(new BigInteger("0"))==0||bigInteger.compareTo(min)==-1)
                min=bigInteger;
        }
        else {
            for (int i = 1; i < line.length; i++) {
                if (list.contains(line[i]))
                    continue;
                else {
                    s += line[i];
                    list.add(line[i]);
                    help(line, s, list);
                    s = s.substring(0, s.length() - line[i].length());
                    list.remove(list.size() - 1);
                }
            }
        }
    }
    public static void main(String[]args)throws IOException {
        BufferedReader br = new BufferedReader(
                new InputStreamReader(System.in)
        );
        String[]line=br.readLine().split(" ");
        help(line,"",new ArrayList<>());
        System.out.println(min);
    }
}
