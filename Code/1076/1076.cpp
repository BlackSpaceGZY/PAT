#include<iostream>
#include<vector>
#define maxSize 1001
using namespace std;

int count=0;
void BFS(vector<int> v[],int m,int L){
	int que[maxSize],rear=0,front=0;
	int set[maxSize]{0};
	rear=(rear+1)%maxSize;
	que[rear]=m;
	set[m]=1;
	while(rear!=front&&L>0){
		int n=rear-front;
		while((n--)>0){
			front=(front+1)%maxSize;
			int p=que[front];
			for(int i=0;i<v[p].size();i++){
				if(set[v[p][i]]==0){
					rear=(rear+1)%maxSize;
					que[rear]=v[p][i];
					set[v[p][i]]=1;
					count++;
				}
			}
		}
		L--;
	}
}
int main(){
	int N,L,k,m;
	cin>>N>>L;
	vector<int> v[N+1];
	for(int i=1;i<=N;i++){
		int n;
		cin>>n;
		for(int j=0;j<n;j++){
			int f;
			cin>>f;
			v[f].push_back(i);
		}
	}
	cin>>k;
	for(int i=0;i<k;i++){
		count=0;
		cin>>m;
		BFS(v,m,L);
		cout<<count<<endl;
	}

	return 0;
}