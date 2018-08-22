#include<iostream>
#include<cctype>
#include<string>
using namespace std;

string s1[]={"tret","jan","feb","mar","apr","may", 
		"jun","jly","aug","sep","oct","nov","dec"};
string s2[]={" ","tam","hel","maa","huh","tou","kes", 
		"hei","elo","syy","lok","mer","jou"};

int printnum(string s,int digit){
	int num=0;
	if(digit==1){
		for(int i=0;i<13;i++){
			if(s==s1[i]){
				num+=i;
				return num;
			}
		}
	}
	else{
		for(int i=0;i<13;i++){
			if(s==s2[i]){
				num+=i*13;
				return num;
			}
		}
		return -1;
	}
}
int main(){
	string n1;
	int N,num;
	getline(cin,n1);
	N=stoi(n1);
	for(int i=0;i<N;i++){
		string s;
		getline(cin,s);
		if(isdigit(s[0])){
			num=stoi(s);
			if(num==0)
				cout<<"tret";
			if(num/13!=0)
				cout<<s2[num/13];
			if(num/13!=0&&num%13!=0)
				cout<<" ";
			if(num%13!=0)
				cout<<s1[num%13];
			cout<<endl;
		}
		else{
			int n1,n2;
			if(s.length()>3&&s!="tret"){
				n1=printnum(s.substr(0,3),2);
				n2=printnum(s.substr(4,6),1);
				cout<<n1+n2<<endl;
			}
			else{
				n1=printnum(s,2);
				if(n1==-1)
					n1=printnum(s,1);
				cout<<n1<<endl;
			}
		}
	}
	return 0;
}