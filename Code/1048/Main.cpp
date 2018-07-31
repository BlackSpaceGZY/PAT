#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	int coins[N];
	for(int i=0;i<N;i++)
		cin>>coins[i];
	sort(coins,coins+N);
	int i=0,j=N-1;
	while(i<j){
		if(coins[i]+coins[j]==M){
			cout<<coins[i]<<" "<<coins[j];
			return 0;
		}
		else if(coins[i]+coins[j]>M)
			j--;
		else
			i++;
	}
	cout<<"No Solution";
	return 0;
}