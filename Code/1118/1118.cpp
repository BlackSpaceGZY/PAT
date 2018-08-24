#include<iostream>
#include<vector>
#include<algorithm>
#define max 10010
using namespace std;

int father[max];
int findFather(int x){
	int a=x;
	while(father[x]!=x)
		x=father[x];
	while(father[a]!=a){
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB)
		father[faA]=faB;
}
int main(){
	int N,q,cnt[max]={0},exist[max]={0};
	cin>>N;
	for(int i=0;i<max;i++)
		father[i]=i;
	for(int i=0;i<N;i++){
		int num;
		cin>>num;
		int a;
		for(int j=0;j<num;j++){
			if(j==0)
				cin>>a;
			else{
				int b;
				cin>>b;
				Union(a,b);
				a=b;
			}
			exist[a]=1;
		}
	}
	for(int i=0;i<max;i++){
		if(exist[i]!=0){
			int root=findFather(i);
			cnt[root]++;
		}
	}
	int numtree=0,numbirds=0;
	for(int i=0;i<max;i++){
		if(cnt[i]!=0){
			numtree++;
			numbirds+=cnt[i];
		}
	}
	cout<<numtree<<" "<<numbirds<<endl;
	cin>>q;
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		if(findFather(a)!=findFather(b))
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
}