#include<iostream>
using namespace std;
int main(){
	double num[1001]={0},a;
	int K,N,cnt=0;
	for(int i=0;i<2;i++){
		cin>>K;
		for(int j=0;j<K;j++){
			cin>>N>>a;
			num[N]+=a;
		}
	}
	for(int i=0;i<1001;i++){
		if(num[i]!=0){
			cnt++;
		}
	}
	cout<<cnt;
	for(int i=1000;i>=0;i--){
		if(num[i]!=0)
			printf(" %d %.1f",i,num[i]);
	}
	return 0;
}