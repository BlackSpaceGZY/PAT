#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int c[255]={0};
	string s1,s2;
	cin>>s1>>s2;
	transform(s1.begin(),s1.end(),s1.begin(),::toupper);
	transform(s2.begin(),s2.end(),s2.begin(),::toupper);
	for(int i=0;i<s2.length();i++)
		c[s2[i]]=1;
	for(int i=0;i<s1.length();i++){
		if(c[s1[i]]==0){
			cout<<s1[i];
			c[s1[i]]=1;
		}
	}
	return 0;
}