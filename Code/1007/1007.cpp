#include<iostream>
using namespace std;
int main(){
	int K,start,end,max=-1,sub=0,l;
	cin>>K;
	int num[K];
	for(int i=0;i<K;i++){
		cin>>num[i];
		sub+=num[i];
		if(sub+num[i]<0){
			sub=0;
			l=i+1;
		}
		else if(sub>max){
			max=sub;
			start=l;
			end=i;
		}
	}
	if(max==-1)
		start=0,end=K-1,max=0;		
	cout<<max<<" "<<num[start]<<" "<<num[end];
	return 0;
}