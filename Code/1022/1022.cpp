#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Book{
	string id,title,author,publisher,year;
	vector<string>keyWords;
};
int cmp(Book b1,Book b2){
	return b1.id<b2.id;
}
void findId(vector<Book>v,int k,string s){
	int flag=0,flag2=-1;
	for(int i=0;i<v.size();i++){
		switch(k){
			case 1:
				flag=v[i].title==s?1:0;
				break;
			case 2:
				flag=v[i].author==s?1:0;
				break;
			case 3:
				for(int j=0;j<v[i].keyWords.size();j++){
					flag=v[i].keyWords[j]==s?1:0;
					if(flag==1)
						break;
				}
				break;
			case 4:
				flag=v[i].publisher==s?1:0;
				break;
			case 5:
				flag=v[i].year==s?1:0;
				break;
		}
		if(flag==1){
			printf("%s\n",v[i].id.c_str());
			flag=flag2=0;
		}
	}
	if(flag2==-1)
		printf("Not Found\n");
}
int main(){
	int k=0;
	string s,N,M;
	char ch;
	vector<Book>v;
	getline(cin,N);
	for(int i=0;i<stoi(N);i++){
		k=0;
		Book book;
		getline(cin,book.id);
		getline(cin,book.title);
		getline(cin,book.author);
		getline(cin,s);
		getline(cin,book.publisher);
		getline(cin,book.year);
		for(int j=0;j<s.length();j++){
			if(s[j]==' '){
				book.keyWords.push_back(s.substr(k,j-k));
				k=j+1;
			}
		}
		book.keyWords.push_back(s.substr(k,s.length()-k));
		v.push_back(book);
	}
	sort(v.begin(),v.end(),cmp);
	getline(cin,M);
	for(int i=0;i<stoi(M);i++){
		getline(cin,s);
		printf("%s\n",s.c_str());
		findId(v,s[0]-'0',s.substr(3,s.length()-3));
	}
	return 0;
}