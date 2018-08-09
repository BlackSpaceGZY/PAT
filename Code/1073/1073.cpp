#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){
	string s,s1="",s2="";
	bool flag=false;
	cin>>s;
	for(int i=1;i<s.length();i++){
		if(s[i]=='E'){
			flag=true;
			continue;
		}
		if(!flag&&isdigit(s[i]))
			s1+=s[i];
		if(flag)
			s2+=s[i];
	}
	int exp;
	exp=stoi(s2);
	if(exp<0){
		for(int i=0;i<-exp;i++)
			s1="0"+s1;
		s1.insert(1,".");
	}
	else{
		int n=s1.length();
		if(n<=exp+1)
			for(int i=0;i<exp+1-n;i++)
				s1+="0";
		else
			s1.insert(exp+1,".");
	}
	if(s[0]=='-')
		printf("-%s\n",s1.c_str());
	else
		printf("%s\n",s1.c_str());
	return 0;
}