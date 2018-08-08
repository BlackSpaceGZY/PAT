#include<iostream>
#include<map>
#include<cctype>
using namespace std;

int main(){
	string s,t;
	getline(cin,s);
	map<string,int>m;
	for(int i=0;i<s.length();i++){
		if(isalnum(s[i])){
			s[i]=tolower(s[i]);
			t+=s[i];
		}
		if(!isalnum(s[i])||i==s.length()-1){
			if(t.length()!=0)m[t]++;
			t="";
		}
	}
	int max=0;
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second>max){
			t=it->first;
			max=it->second;
		}
	}
	cout<<t<<" "<<max;
	return 0;
}