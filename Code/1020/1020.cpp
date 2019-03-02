#include<iostream>
using namespace std;

void found(int level[],int pos,
	int in[],int post[],int l1,int r1,int l2,int r2){
	if(l1>r1)
		return;
	int j=l1;
	while(j<=r1&&in[j]!=post[r2])
		j++;
	level[pos]=post[r2];
	found(level,pos*2,in,post,l1,j-1,l2,l2+j-l1-1);
	found(level,pos*2+1,in,post,j+1,r1,l2+j-l1,r2-1);

}
int main(){
	int N,in[31],post[31],level[10000]={0},cnt=0;
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>post[i];
	for(int i=1;i<=N;i++)
		cin>>in[i];
	found(level,1,in,post,1,N,1,N);
	cout<<level[1];
	for(int i=2;i<10000&&cnt<=N;i++){
		if(level[i]!=0){
			cout<<" "<<level[i];
			cnt++;
		}
	}
	return 0;
}