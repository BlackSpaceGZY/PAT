#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int c,n,s,m,inf=99999,minn,u;
	int a,b,d,n1,n2;
	string str;
	cin>>c>>n>>s>>m;
	int dist[n+1],weight[n+1],e[n+1][n+1],visit[n+1],path[n+1]
	,w[n+1],pass[n+1];
	fill(e[0],e[0]+(n+1)*(n+1),inf);
	fill(dist,dist+n+1,inf);
	fill(path,path+n+1,0);
	fill(pass,pass+n+1,0);
	fill(visit,visit+n+1,0);
	for(int i=1;i<=n;i++)
		cin>>weight[i];
	for(int i=0;i<m;i++){
		cin>>a>>b>>d;
		e[a][b]=e[b][a]=d;
	}
	dist[0]=0;
	weight[0]=w[0]=0;
	path[0]=-1;
	for(int i=0;i<=n;i++){
		minn=inf;
		for(int j=0;j<=n;j++){
			if(visit[j]==0&&dist[j]<minn){
				u=j;
				minn=dist[j];
			}
		}
		visit[u]=1;
		for(int v=0;v<=n;v++){
			if(visit[v]==0){
				if(dist[u]+e[u][v]<dist[v]){
					dist[v]=dist[u]+e[u][v];
					w[v]=w[u]+weight[v];
					path[v]=u;
					pass[v]=pass[u]+1;
				}
				else if(dist[u]+e[u][v]==dist[v]){
					n1=c*(pass[u]+1)/2-(w[u]+weight[v]);
					n2=c*pass[v]/2-w[v];
					if(((n1<n2)&&n2>0)||((n1>n2)&&n1<0&&n2<0)){
						w[v]=w[u]+weight[v];
						path[v]=u;
						pass[v]=pass[u]+1;		
					}
				}
			}
		}
	}
	if(c*pass[s]/2-w[s]<0)
		cout<<0<<" ";
	else
		cout<<c*pass[s]/2-w[s]<<" ";
	int j=s;
	while(path[j]!=-1){
		str=to_string(path[j])+"->"+str;
		j=path[j];
	}
	cout<<str<<s<<" ";
	if(c*pass[s]/2-w[s]>0){
		cout<<0;
	}
	else
		cout<<w[s]-c*pass[s]/2;
	return 0;
}