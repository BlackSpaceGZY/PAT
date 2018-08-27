#include<iostream>
#include<vector>
using namespace std;

typedef struct node{
	string s;
	int left;
	int right;
}node;
int root;
void inorder(int r,vector<node>v){
	if(r!=root&&(v[r].left!=-1||v[r].right!=-1))
		cout<<"(";
	if(v[r].left!=-1)
		inorder(v[r].left,v);
	cout<<v[r].s;
	if(v[r].right!=-1)
		inorder(v[r].right,v);
		if(r!=root&&(v[r].left!=-1||v[r].right!=-1))
		cout<<")";
}
int main(){
	int N;
	cin>>N;
	root=((N+1)*N)/2;
	vector<node>v(N+1);
	for(int i=1;i<=N;i++){
		node n;
		cin>>n.s>>n.left>>n.right;
		if(n.left!=-1)
			root-=n.left;
		if(n.right!=-1)
			root-=n.right;
		v[i]=n;
	}
	inorder(root,v);
	return 0;
}