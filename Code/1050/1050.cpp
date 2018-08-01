#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

int main(){
	string s1;
	string s2;
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s2.length();i++){
		char c=s2[i];
		int pos=s1.find(c);
		while(pos!=-1){
			s1.replace(pos,1,"");
			pos=s1.find(c);
		}
	}
	printf("%s\n",s1.c_str());
	return 0;
}
