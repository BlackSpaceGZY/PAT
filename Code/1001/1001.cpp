#include<iostream>
using namespace std;
int main() {
	int a,b;
	cin>>a>>b;
	string s=to_string(a+b);
	int len=s.length();
	for(int i=0; i<len; i++) {
		cout<<s[i];
		if(s[i]=='-')
			continue;
		if((len-i-1)%3==0&&i!=len-1)
			cout<<",";
	}
	return  0;
}


