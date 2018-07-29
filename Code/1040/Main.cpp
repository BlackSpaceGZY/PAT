#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	for(int i=0;i<=s.length();i+=2)
		s.insert(i,"#");
	int ml=0,mr=0,max=1;
	for(int i=1;i<s.length();i++){
		int l=i-1;
		int r=i+1;
		while(l!=-1&&s[l]==s[r]){
			r++;
			l--;
		}
		if(max<r-l-1){
			max=r-l-1;
			ml=l+1;
			mr=r-1;
		}
	}
	printf("%d\n",(mr-ml)/2 );
	return 0;
}