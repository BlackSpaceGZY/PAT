#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n,m,s,d,inf=99999,a,b,c,x,minn,u,v,distance=0;
	cin>>n>>m>>s>>d;
	int weight[n][n],e[n][n],dist[n],visit[n],w[n],path[n];
	fill(weight[0],weight[0]+n*n,0);
	fill(e[0],e[0]+n*n,inf);
	fill(dist,dist+n,inf);
	fill(path,path+n,-1);
	fill(visit,visit+n,0);
	for(int i=0;i<m;i++){
		cin>>a>>b>>c>>x;
		e[a][b]=e[b][a]=c;
		weight[a][b]=weight[b][a]=x;
	}
	dist[s]=0;
	w[s]=0;
	for(int i=0;i<n;i++){
		minn=inf;
		for(int j=0;j<n;j++){
			if(visit[j]==0&&dist[j]<minn){
				u=j;
				minn=dist[i];
			}
		}
		visit[u]=1;
		for(int v=0;v<n;v++){
			if(visit[v]==0&&dist[u]+e[u][v]<dist[v]){
				dist[v]=dist[u]+e[u][v];
				w[v]=w[u]+weight[u][v];
				path[v]=u;
			}
			else if(visit[v]==0&&dist[u]+e[u][v]==dist[v]){
				if(w[v]>w[u]+e[u][v]){
					w[v]=w[u]+weight[u][v];
					path[v]=u;		
				}
			}
		}
	}
	int j=d;
	string str;
	while(j!=-1){
		str=to_string(j)+" "+str;
		if(path[j]!=-1)
			distance+=e[path[j]][j];
		j=path[j];
	}
	cout<<str<<distance<<" "<<w[d]<<endl;
	return 0;
}