#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
	int N,M;
	int roads=0;
	int road[N];
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		cin>>road[i];
		roads+=road[i];
	}
	scanf("%d",&M);
	int first;
	int second;
	for(int i=0;i<M;i++){
		scanf("%d",&first);
		scanf("%d",&second);
		int pos=first-1;
		int length=0;
		while((pos+1)%N!=(second-1)){
			length+=road[pos];
			pos=(pos+1)%N;
		}
		length+=road[pos];
		printf("%d\n",length>roads-length?roads-length:length);
	}
	return 0;
}
