#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	vector<int>v[N+1];
	for(int i=0;i<M;i++){
		int id,num;
		cin>>id>>num;
		for(int j=0;j<num;j++){
			int m;
			cin>>m;
			v[id].push_back(m);
		}
	}
	int queue[101],front=0,rear=0,level=1,maxlevel=1,max=1,count=1;
	queue[++rear]=1;
	while(front!=rear){
		int nowcount=0;
		while((count--)>0){
			int a=queue[++front];
			for(int i=0;i<v[a].size();i++){
				queue[++rear]=v[a][i];
				nowcount++;
			}
		}
		if(max<nowcount){
			max=nowcount;
			maxlevel=level+1;
		}
		count=nowcount;
		level++;
	}
	printf("%d %d\n",max,maxlevel);
	return 0;
}