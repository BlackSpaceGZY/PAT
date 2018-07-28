import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static String change(String s){
        s=s.replace('0','%');
        s=s.replace('1','@');
        s=s.replace('O','o');
        s=s.replace('l','L');
        return s;
    }
    public static void main(String[]args)throws IOException{
        BufferedReader br=new BufferedReader(
                new InputStreamReader(System.in)
        );
        List<Student>s=new ArrayList<>();
        int N=Integer.valueOf(br.readLine());
        for(int i=0;i<N;i++){
            String[]line=br.readLine().split(" ");
            if(!line[1].equals(change(line[1]))) {
                line[1]=change(line[1]);
                s.add(new Student(line[0],line[1]));
            }
        }
        if(s.size()==0){
            if(N==1)
                System.out.println("There is 1 account and no account is modified");
            else
                System.out.println("There are "+N+" accounts and no account is modified");
        }
        else{
            System.out.println(s.size());
            for(Student st:s)
                System.out.println(st.name+" "+st.password);

        }
    }
}
class Student{
    String name;
    String password;
    public Student(String name,String password){
        this.name=name;
        this.password=password;
    }
}
