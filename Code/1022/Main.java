import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    static List<String>query_id=new ArrayList<>();
    public static void query(Book[]library,int n,String s){
        switch (n){
            case 1:
                for(Book book:library)
                    compare(book,book.title,s);
                break;
            case 2:
                for(Book book:library)
                    compare(book,book.author,s);
                break;
            case 3:
                for(Book book:library){
                    for(int i=0;i<book.keyword.length;i++)
                        if(compare(book,book.keyword[i],s))
                            break;
                }
                break;
            case 4:
                for(Book book:library)
                    compare(book,book.publisher,s);
                break;
            case 5:
                for(Book book:library)
                    compare(book,book.year,s);
                break;
        }
    }
    public static boolean compare(Book book,String s1,String s2){
        if(s1.equals(s2)) {
            query_id.add(book.id);
            return true;
        }
        return false;
    }
    public static void main(String[]args)throws Exception{
        BufferedReader br=new BufferedReader(
                new InputStreamReader(System.in)
        );
        int N=Integer.valueOf(br.readLine());
        Book[] library=new Book[N];
        for(int i=0;i<library.length;i++)
            library[i]=new Book(br.readLine(),br.readLine(),br.readLine(),
                    br.readLine().split(" "),br.readLine(),
                    br.readLine());
        int M=Integer.valueOf(br.readLine());
        String[]querys=new String[M];
        for (int i=0;i<M;i++)
            querys[i]=br.readLine();
        for(int i=0;i<M;i++){
            System.out.println(querys[i]);
            query(library,querys[i].charAt(0)-'0',querys[i].substring(3));
            if(query_id.size()==0)
                System.out.println("Not Found");
            else {
                Collections.sort(query_id);
                for (String id:query_id)
                    System.out.println(id);
                query_id.clear();
            }
        }
    }
}
class Book{
    String id;
    String title;
    String author;
    String[]keyword;
    String publisher;
    String year;
    public Book (String id,String title,String author,
                 String[]keyword,String publisher,String year){
        this.id=id;
        this.title=title;
        this.author=author;
        this.keyword=keyword;
        this.publisher=publisher;
        this.year=year;
    }
}