#include<iostream>
using namespace std;

int gcd(int n,int m){
	int d=n%m;
	return d==0?m:gcd(m,d);
}
int C(int n,int k){
	int m=1,x=n;
	for(int i=1;i<k;i++){
		n*=(x-i);
		m*=(i+1);
		int z=gcd(n,m);
		n/=z;
		m/=z;
	}
	return n/m;
}
int main(){
	int N;
	double sum=0;
	cin>>N;
	double nums[N];
	for(int i=0;i<N;i++){
		double num;
		cin>>num;
		nums[i]=num;
	}
	for(int i=1;i<=N/2;i++)
		sum+=(nums[i-1]+nums[N-i])*C(N,i);
	if(N%2!=0)
		sum+=nums[N/2]*C(N,N/2+1);
	printf("%.2f\n",sum);
	return 0;
}