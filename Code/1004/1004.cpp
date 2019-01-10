#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,m,a,k,b,c,count=0,cnt=1;
	bool flag=true;
	cin>>n>>m;
	vector<int>v[n+1];
	int que[10000];
	int front=0,rear=0;
	for(int i=0;i<m;i++){
		cin>>a>>k;
		for(int j=0;j<k;j++){
			cin>>b;
			v[a].push_back(b);
		}
	}
	que[++rear]=1;
	while(rear!=front){
		c=que[++front];
		for(int i=0;i<v[c].size();i++){
			que[++rear]=v[c][i];
		}
		if(v[c].size()==0)
			count++;
		if(cnt==front){
			if(cnt==1)
				cout<<count;
			else
				cout<<" "<<count;
			count=0;
			cnt=rear;
		}
		flag=true;
	}
	return 0;
}