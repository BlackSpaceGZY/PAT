#include<iostream>
#include<vector>
using namespace std;

void fun1(int N,vector<int>v[],int root){
	int a[N],que[100],rear=0,front=0,n,count=1,i=0;
	que[++rear]=root;
	while(front!=rear){
		while((count--)>0){
			n=que[++front];
			a[i++]=n;
			if(v[n][0]!=-1)
				que[++rear]=v[n][0];
			if(v[n][1]!=-1)
				que[++rear]=v[n][1];
		}
		count=rear-front;
	}
	for(int i=0;i<N;i++){
		if(i!=0)
			cout<<" ";
		cout<<a[i];
	}
}
vector<int>w;
void fun2(vector<int>v[],int root){
	if(root==-1)
		return;
	if(v[root][0]!=-1)
		fun2(v,v[root][0]);
	w.push_back(root);
	if(v[root][1]!=-1)
		fun2(v,v[root][1]);
}
int main(){
	int N,root;
	cin>>N;
	root=(N*(N-1))/2;
	vector<int>v[N];
	for(int i=0;i<N;i++){
		char c1,c2;
		cin>>c1>>c2;
		if(c2=='-')
			v[i].push_back(-1);
		else{
			v[i].push_back(c2-'0');
			root-=(c2-'0');
		}
		if(c1=='-')
			v[i].push_back(-1);
		else{
			v[i].push_back(c1-'0');
			root-=(c1-'0');
		}
	}
	fun1(N,v,root);
	cout<<endl;
	fun2(v,root);
	for(int i=0;i<w.size();i++){
		if(i!=0)
			cout<<" ";
		cout<<w[i];
	}
	return 0;
}