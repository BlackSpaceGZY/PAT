import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[]args)throws Exception{
        Scanner sc=new Scanner(
                new InputStreamReader(System.in)
        );
        List<Student>all=new ArrayList<>();
        int N=sc.nextInt();
        for(int k=0;k<N;k++){
            int K=sc.nextInt();
            for(int i=0;i<K;i++)
                all.add(new Student(sc.next(), k, sc.nextInt()));
        }
        Collections.sort(all);
        int[]location_rank=new int[N];
        int[]location_count=new int[N];
        int[]location_formerscore=new int[N];
        int former=0;
        int rank=0;
        int count=1;
        System.out.println(all.size());
        for(int i=0;i<all.size();i++){
            Student s=all.get(i);
            if(former==s.score)
                count++;
            else{
                former=s.score;
                rank+=count;
                count=1;
            }
            if(location_formerscore[s.location]==s.score)
                location_count[s.location]++;
            else{
                location_formerscore[s.location]=s.score;
                location_rank[s.location]+=location_count[s.location];
                location_count[s.location]=1;
            }
            System.out.println(all.get(i).id+" "+rank+" "
                    +(s.location+1)+
            " "+(location_rank[s.location]+1));
        }
    }
}
class Student implements Comparable<Student>{
    String id;
    int location;
    int score;
    public Student(String id,int location,int score){
        this.id=id;
        this.location=location;
        this.score=score;
    }

    @Override
    public int compareTo(Student o) {
        if(this.score>o.score)
            return -1;
        else if(this.score<o.score)
            return 1;
        else {
            for(int i=0;i<this.id.length();i++){
                if (this.id.charAt(i) > o.id.charAt(i))
                    return 1;
                if(this.id.charAt(i)<o.id.charAt(i))
                    return -1;
            }
            return -1;
        }
    }
}
