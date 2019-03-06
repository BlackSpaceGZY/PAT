#include<iostream>
using namespace std;

int main(){
	string s;
	cin>>s;
	int n1,n3,len;
	n1=s.length()/3;
	n3=n1+s.length()%3;
	if(s.length()%3==0){
		n1-=1;
		n3+=2;
	}
	for(int i=0;i<n1;i++){
		printf("%c",s[i]);
		for(int j=0;j<n3-2;j++)
			printf("%s"," ");
		printf("%c\n",s[s.length()-i-1]);
	}
	printf("%s\n",s.substr(n1,n3).c_str());
	return 0;
}