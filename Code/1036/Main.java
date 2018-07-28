import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[]args)throws IOException {
        BufferedReader br = new BufferedReader(
                new InputStreamReader(System.in)
        );
        Student male=new Student();
        Student female=new Student();
        int N=Integer.valueOf(br.readLine());
        for(int i=0;i<N;i++){
            String[]line=br.readLine().split(" ");
            if(line[1].equals("M")){
                if(male.name==null||male.grade>Integer.valueOf(line[3]))
                    male.add(line[0],line[1],line[2],Integer.valueOf(line[3]));
            }
            else if(line[1].equals("F")){
                if(female.name==null||female.grade<Integer.valueOf(line[3]))
                    female.add(line[0],line[1],line[2],Integer.valueOf(line[3]));
            }
        }
        if(female.name!=null)
            System.out.println(female.name+" "+female.id);
        else
            System.out.println("Absent");
        if(male.name!=null)
            System.out.println(male.name+" "+male.id);
        else
            System.out.println("Absent");
        if(female.name!=null&&male.name!=null)
            System.out.println(female.grade-male.grade);
        else
            System.out.println("NA");
    }
}

class Student{
    String name;
    String gender;
    String id;
    int grade;
    public Student(String name,String gender,String id,int grade){
        this.name=name;
        this.gender=gender;
        this.id=id;
        this.grade=grade;
    }
    public Student(){}
    public void add(String name,String gender,String id,int grade){
        this.name=name;
        this.gender=gender;
        this.id=id;
        this.grade=grade;
    }
}
