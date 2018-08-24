#include<iostream>
#include<algorithm>
using namespace std;

int cmp(int a,int b){
	return a>b;
}
int main(){
	int N,days=0;
	cin>>N;
	int arra[N+1];
	for(int i=1;i<=N;i++){
		cin>>arra[i];
	}
	sort(arra+1,arra+1+N,cmp);
	for(int i=1;i<=N;i++){
		if(arra[i]>i)
			days++;
		else
			break;
	}
	cout<<days;
	return 0;
}