#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int num){
	if(num==1)
		return false;
	for(int i=2;i<=sqrt(num);i++)
		if(num%i==0)
			return false;
	return true;
}

void isReverseNumber(int N,int D){
	if(isPrime(N)==false)
		cout<<"No"<<endl;
}
int main(){
	int num,radix;
	while(true){
		cin>>num;
		if(num<0)
			break;
		cin>>radix;

	}
	return 0;
}