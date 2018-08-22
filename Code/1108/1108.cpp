#include<iostream>
#include<cctype>
#include<cmath>
using namespace std;

bool islegal(string s){
	bool flag=true;
	int count=0;
	int i=0;
	if(s[0]=='-'){
		i=1;
		if(s.length()==1)
			return false;
	}
	for(;i<s.length();i++){
		if(isdigit(s[i])==false){
			if(s[i]=='.'&&flag==true){
				flag=false;
				continue;
			}
			else
				return false;
		}
		else{
			if(flag==false)
				count++;
			if(count>2)
				return false;
		}
	}
	return true;
}
int main(){
	int N;
	cin>>N;
	double sum=0,k=0;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		if(islegal(s)==false){
			cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
			continue;
		}
		else{
			double a=stod(s);
			if(abs(a)>1000){
				cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
				continue;
			}
			sum+=a;
			k++;
		}
	}
	if(k==0)
		cout<<"The average of 0 numbers is Undefined";
	else{
		double average;
		average=sum/k;
		cout<<"The average of "<<k<<" numbers is ";
		printf("%.2f\n",average);
	}
	return 0;
}