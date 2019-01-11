#include<iostream>
using namespace std;
int main(){
	int K1,K2,a,cnt=0;
	double num1[1001]={0},num2[1001]={0},num3[2001]={0};
	cin>>K1;
	for(int i=0;i<K1;i++){
		cin>>a;
		cin>>num1[a];
	}
	cin>>K2;
	for(int i=0;i<K2;i++){
		cin>>a;
		cin>>num2[a];
	}
	for(int i=0;i<1001;i++){
		if(num1[i]==0)
			continue;
		for(int j=0;j<1001;j++)
			num3[i+j]+=num1[i]*num2[j];
	}
	for(int i=0;i<2001;i++){
		if(num3[i]!=0)
			cnt++;
	}
	cout<<cnt;
	for(int i=2000;i>=0;i--){
		if(num3[i]!=0)
			printf(" %d %.1f",i,num3[i]);
	}
	return 0;
}