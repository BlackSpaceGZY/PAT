#include<cstdio>
#include<algorithm>
using namespace std;
int roads[1001][1001]={0};
int flag[1001];
void find(int k){
	flag[k]=1;
	for(int i=1;i<1001;i++){
		if(flag[i]==0&&roads[k][i]==1)
			find(i);
	}
}
int main(){
	int N,M,K,a,b,c,cnt=0;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		roads[a][b]=roads[b][a]=1;
	}
	for(int i=0;i<K;i++){
		scanf("%d",&c);
		fill(flag,flag+1001,0);
		flag[c]=1;
		for(int j=1;j<=N;j++){
			if(flag[j]==0){
				find(j);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
		cnt=0;
	}
	return 0;
}