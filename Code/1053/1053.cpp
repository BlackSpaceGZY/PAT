#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>v[101];
vector<int>w;
int weight[101];
void help(int weights,int index){
	if(weights==0&&v[index].size()==0){
		for(vector<int>::iterator it=w.begin();(it+1)!=w.end();it++)
			printf("%d ",*it);
		printf("%d\n",w[w.size()-1]);
		return;
	}
	for(int i=0;i<v[index].size();i++){
		if(weights-weight[v[index][i]]>=0){
			weights-=weight[v[index][i]];
			w.push_back(weight[v[index][i]]);
			help(weights,v[index][i]);
			weights+=weight[v[index][i]];
			w.pop_back();
		}
	}
}
bool cmp(int a,int b){
	return weight[a]>weight[b];
}
int main(){
	int num,no_leaf,weights;
	scanf("%d%d%d",&num,&no_leaf,&weights);
	for(int i=0;i<num;i++)
		scanf("%d",&weight[i]);
	for(int i=0;i<no_leaf;i++){
		int a,num;
		scanf("%d%d",&a,&num);
		for(int j=0;j<num;j++){
			int b;
			scanf("%d",&b);
			v[a].push_back(b);
		}
		sort(v[a].begin(),v[a].end(),cmp);
	}
	w.push_back(weight[0]);
	help(weights-weight[0],0);

	return 0;

}