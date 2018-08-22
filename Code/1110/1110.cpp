#include<iostream>
#include<vector>
using namespace std;

void bfs(vector<int>v[],int N,int root){
	int que[1000],rear=0,front=0,n;
	que[++rear]=root;
	N--;
	if(N==0){
		cout<<"YES "<<root;
		return;
	}
	while(rear!=front){
		n=que[++front];
		for(int i=0;i<v[n].size();i++){
			if(v[n][i]==-1){
				if(N>0)
					cout<<"NO "<<root;
				else
					cout<<"YES "<<que[rear];
				return;
			}
			que[++rear]=v[n][i];
			N--;
		}
	}
}
int main(){
	int N,root;
	cin>>N;
	vector<int>v[N];
	root=N*(N-1)/2;
	for(int i=0;i<N;i++){
		char c1,c2;
		cin>>c1>>c2;
		if(c1=='-')
			v[i].push_back(-1);
		else{
			v[i].push_back(c1-'0');
			root-=(c1-'0');
		}
		if(c2=='-')
			v[i].push_back(-1);
		else{
			v[i].push_back(c2-'0');
			root-=(c2-'0');
		}
	}
	bfs(v,N,root);
	return 0;
}