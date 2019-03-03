#include<iostream>
using namespace std;

string add(string s){
	string str;
	int cnt=0;
	for(int i=s.length()-1;i>=0;i--){
		str=to_string(((s[i]-'0')*2+cnt)%10)+str;
		if(s[i]>='5')
			cnt=1;
		else
			cnt=0;
	}
	if(cnt>0)
		str="1"+str;
	return str;
}
int main(){
	int count[10]={0};
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
		count[s[i]-'0']++;
	s=add(s);
	for(int i=0;i<s.length();i++)
		count[s[i]-'0']--;
	int i=0;
	for(;i<s.length();i++){
		if(count[s[i]-'0']!=0){
			cout<<"No"<<endl;
			break;
		}
	}
	if(i==s.length())
		cout<<"Yes"<<endl;
	cout<<s<<endl;
	return 0;
}
