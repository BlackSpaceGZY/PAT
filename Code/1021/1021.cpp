#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void findDeep(vector<int>v[],int deep,int *max,int now,int visit[]){
	visit[now]=1;
	for(int i=0;i<v[now].size();i++){
		if(visit[v[now][i]]==0)
			findDeep(v,deep+1,max,v[now][i],visit);
	}
	if(deep>*max)
			*max=deep;
}
void dfs(vector<int>v[],int n,int visit[]){
	visit[n]=1;
	for(int i=0;i<v[n].size();i++){
		if(visit[v[n][i]]==0)
			dfs(v,v[n][i],visit);
	}
}
int main(){
	int N,a,b,components=0,max=0;
	vector<int> v[10001],v1;
	cin>>N;
	int visit[N+1]={0};
	for(int i=0;i<N-1;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=N;i++){
		if(visit[i]==0){
			components++;
			dfs(v,i,visit);
		}
	}
	if(components>1)
		cout<<"Error: "+to_string(components)+" components"<<endl;
	else{
		int d=1;
		for(int i=1;i<=N;i++){
			fill(visit,visit+N+1,0);
			findDeep(v,1,&d,i,visit);
			if(d==max)
				v1.push_back(i);
			else if(d>max){
				v1.clear();
				v1.push_back(i);
				max=d;
			}
			d=1;
		}
		for(int i=0;i<v1.size();i++)
			cout<<v1[i]<<endl;
	}
	return 0;
}