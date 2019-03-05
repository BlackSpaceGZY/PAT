#include<iostream>
using namespace std;

string switches(int n){
	if(n==0)
		return "00";
	string s;
	int m=0;
	while(n>0){
		m=n%13;
		if(m==10)
			s="a"+s;
		else if(m==11)
			s="b"+s;
		else if(m==12)
			s="c"+s;
		else
			s=to_string(m)+s;
		n/=13;
	}
	if(s.length()==1)
		s="0"+s;
	return s;
}
int main(){
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	cout<<"#"<<switches(n1)<<switches(n2)<<switches(n3);
	return 0;
}