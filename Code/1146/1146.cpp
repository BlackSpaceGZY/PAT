#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N,M,K;
	cin>>N>>M;
	vector< vector<int> >v;
	v.resize(N+1,vector<int>(N+1,0));
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		v[b][a]=1;
	}
	cin>>K;
	int d=0;
	vector< vector<int> >v1;
	vector<int>v2;
	v1=v;
	for(int i=0;i<K;i++){
		bool flag=true;
		for(int j=0;j<N;j++){
			int a;
			cin>>a;
			if(flag==false)
				continue;
			for(int k=1;k<v1[a].size();k++){
				if(v1[a][k]!=0){
					flag=false;
					break;
				}
				else
					v1[k][a]=0;
			}
		}
		if(flag==false){
			v2.push_back(i);
		}
		v1=v;
	}
	for(int i=0;i<v2.size();i++){
		if(i!=0)
			cout<<" ";
		cout<<v2[i];
	}
	return 0;
}