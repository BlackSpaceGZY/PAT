#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

typedef struct node{
	int data;
	int next;
}node;
int main(){
	vector<node>v[100001];
	int start,n,hash[10001]={0};
	cin>>start>>n;
	int nn[n];
	for(int i=0;i<n;i++){
		int a,d,ne;
		node node;
		cin>>a>>d>>ne;
		nn[i]=a;
		node.data=d;
		node.next=ne;
		v[a].push_back(node);
	}
	bool flag=true;
	vector<int> v1;
	while(start!=-1){
		if(hash[abs(v[start][0].data)]==0){
			if(flag==false)
				printf("%05d\n",start);
			printf("%05d %d ",start,v[start][0].data);
			hash[abs(v[start][0].data)]++;
			flag=false;
			start=v[start][0].next;
		}
		else{
			if(v1.size()!=0)
				v1.push_back(start);
			v1.push_back(start);
			v1.push_back(v[start][0].data);
			start=v[start][0].next;
		}
	}
	printf("%d\n",-1);
	for(int j=0;j<v1.size();j++){
		if((j+1)%3!=0){
			if((j+1)%3==1)
		 		printf("%05d ",v1[j]);
		 	else
		 		printf("%d ",v1[j]);
		}
		else
			printf("%05d\n",v1[j]);
	}
	if(v1.size()!=0)
		printf("-1");
	return 0;
}