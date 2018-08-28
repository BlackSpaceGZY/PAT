#include<iostream>
#include<vector>
using namespace std;

typedef struct node{
	int address;
	int data;
	int next;
}node;
int main(){
	int start,N,K,index;
	cin>>start>>N>>K;
	vector<node>v;
	for(int i=0;i<N;i++){
		int add,data,next;
		cin>>add>>data>>next;
		if(start==add)
			index=i;
		node node;
		node.address=add;
		node.data=data;
		node.next=next;
		v.push_back(n);
	}
	return 0;
}