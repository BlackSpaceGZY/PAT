#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int N,M,C1,C2;
	int a,b,c,u,minn;
	int inf=99999;
	cin>>N>>M>>C1>>C2;
	int e[N][N],dist[N],weight[N],num[N],w[N],visit[N];
	fill(e[0],e[0]+N*N,inf);
	fill(dist,dist+N,inf);
	fill(visit,visit+N,0);
	for(int i=0;i<N;i++)
		cin>>weight[i];
	for(int i=0;i<M;i++){
		cin>>a>>b>>c;
		e[a][b]=e[b][a]=c;
	}
	w[C1]=weight[C1];
	dist[C1]=0;
	num[C1]=1;
	for(int i=0;i<N;i++){
		minn=inf,u=-1;
		for(int j=0;j<N;j++){
			if(visit[j]==0&&dist[j]<minn){
				u=j;
				minn=dist[j];
			}
		}
		if(u==-1)
			break;
		visit[u]=1;
		for(int v=0;v<N;v++){
			if(visit[v]==0){
				if(e[u][v]+dist[u]<dist[v]){
					dist[v]=e[u][v]+dist[u];
					w[v]=w[u]+weight[v];
					num[v]=num[u];
				}
				else if(e[u][v]+dist[u]==dist[v]){
					w[v]=max(w[v],w[u]+weight[v]);
					num[v]=num[u]+num[v];
				}
			}
		}
	}
	cout<<num[C2]<<" "<<w[C2];
	return 0;
}