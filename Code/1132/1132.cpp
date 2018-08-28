#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		string s,s1,s2;
		cin>>s;
		s1=s.substr(0,s.length()/2);
		s2=s.substr(s.length()/2,s.length());
		int a,b,c;
		a=stoi(s);
		b=stoi(s1);
		c=stoi(s2);
		if(c==0||a%(b*c)!=0)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}