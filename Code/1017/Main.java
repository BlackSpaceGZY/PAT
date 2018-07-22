import java.text.DecimalFormat;
import java.util.*;

public class Main {
    public static int find(long[]windows){
        int min=0;
        for(int i=1;i<windows.length;i++)
            if(windows[min]>windows[i])
                min=i;
        return min;
    }
    public static long getSeconds(String s){
        return Integer.parseInt(s.substring(3,5))*60+
                Integer.parseInt(s.substring(6,8));
    }
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int K=sc.nextInt();
        Map<String,Integer>map=new HashMap<>();
        for(int i=0;i<N;i++)
            map.put(sc.next(),sc.nextInt());
        Object []key=map.keySet().toArray();
        Arrays.sort(key);
        long wait=0;
        long[] windows=new long[K];
        int latter=0;
        for(int i=0;i<key.length;i++){
            int realH=Integer.parseInt(key[i].toString().substring(0,2));
            int H=realH<8?8:realH;
            long seconds=realH<8?0:getSeconds(key[i].toString());
            //before 8：00
            if(realH<8)
                wait+=3600*(7-realH)+3600-getSeconds(key[i].toString());
            //after 17:00
            if(seconds+H*3600>17*3600)
                latter++;
            int j=find(windows);
            //should wait
            if(windows[j]>(H-8)*3600+seconds){
                wait+=windows[j]-(H-8)*3600-seconds;
                windows[j]+=map.get(key[i])*60;
            }
            //should'nt wait
            else
                windows[j]=(H-8)*3600+seconds+map.get(key[i])*60;
        }
        DecimalFormat df=new DecimalFormat("#.0");
        System.out.print(df.format(((double)wait/(N-latter)/60)));
    }
}
