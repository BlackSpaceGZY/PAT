import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[]args)throws IOException{
        BufferedReader br=new BufferedReader
                (new InputStreamReader(System.in));
        String[]line1=br.readLine().split(" ");
        int N=Integer.valueOf(line1[0]);
        int C=Integer.valueOf(line1[1]);
        Student[] students=new Student[N];
        for(int i=0;i<N;i++){
            String []s=br.readLine().split(" ");
            students[i]=new Student(s[0],s[1],s[2],C);
        }
        Arrays.sort(students);
        for(int i=0;i<students.length;i++)
            System.out.println(students[i].id+" "+students[i].name+" "+students[i].score);
    }
}

class Student implements Comparable<Student>{
    String id;
    String name;
    String score;
    int C;
    public Student(String id,String name,String score,int C){
        this.id=id;
        this.name=name;
        this.score=score;
        this.C=C;
    }
    public int compareName(Student o){
        for(int i=0;i<this.name.length();i++){
            if(o.name.length()-1<i)
                return 1;
            if(this.name.charAt(i)>o.name.charAt(i))
                return 1;
            if (this.name.charAt(i)<o.name.charAt(i))
                return -1;
        }
        if(o.name.length()>this.name.length())
            return -1;
        else
            return 0;
    }
    @Override
    public int compareTo(Student o) {
        if(this.C==1){
            if(Long.valueOf(this.id)>Long.valueOf(o.id))
                return 1;
            else
                return -1;
        }
        else if(this.C==2){
            if(this.compareName(o)==0){
                if(Long.valueOf(this.id)>Long.valueOf(o.id))
                    return 1;
                else
                    return -1;
            }
            else
                return compareName(o);
        }
        else{
            if(this.score.equals(o.score)){
                if(Long.valueOf(this.id)>Long.valueOf(o.id))
                    return 1;
                else
                    return -1;
            }
            else{
                if(Integer.valueOf(this.score)>Integer.valueOf(o.score))
                    return 1;
                else
                    return -1;
            }
        }
    }
}
