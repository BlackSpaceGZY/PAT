#include<iostream>
using namespace std;

string add(string s1,string s2){
	string str;
	int cnt=0;
	for(int i=s1.length()-1;i>=0;i--){
		str=to_string((s1[i]-'0'+s2[i]-'0'+cnt)%10)+str;
		if(s1[i]-'0'+s2[i]-'0'+cnt>=10)
			cnt=1;
		else
			cnt=0;
	}
	if(cnt>0)
		str="1"+str;
	return str;
}
string reverse(string s){
	string s1;
	for(int i=s.length()-1;i>=0;i--)
		s1+=to_string(s[i]-'0');
	return s1;
}
int main(){
	string s;
	int n,i=0;
	cin>>s>>n;
	for(;i<n;i++){
		if(reverse(s)==s)
			break;
		s=add(s,reverse(s));
	}
	cout<<s<<endl;
	cout<<i<<endl;
	return 0;
}