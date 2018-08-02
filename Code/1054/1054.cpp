#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;

map<int,int>m;
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			int K;
			scanf("%d",&K);
			if(m.find(K)!=m.end())
				m[K]=m[K]+1;
			else
				m[K]=1;
		}
	}
	int num=0;
	int v=0;
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
		if(it->second>num){
			num=it->second;
			v=it->first;
		}
	}
	printf("%d\n",v);
	return 0;
}