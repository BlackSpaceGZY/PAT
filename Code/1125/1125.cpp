#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int cmp(double a,double b){
	return a>b;
}
int main(){
	int N;
	cin>>N;
	double arra[N];
	for(int i=0;i<N;i++)
		cin>>arra[i];
	sort(arra,arra+N,cmp);
	double sum=0;
	for(int i=0;i<N-1;i++){
		sum+=arra[i]/pow(2,i+1);
	}
	sum+=arra[N-1]/pow(2,N-1);
	int a=floor(sum);
	cout<<a;
	return 0;
}