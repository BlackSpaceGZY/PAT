#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct{
	int address;
	int data;
	int next;
}Node;
vector<Node> list[100001];
vector<Node> l;
bool cmp(Node n1,Node n2){
	return n1.data<n2.data;
}
int main(){
	int N,head;
	scanf("%d%d",&N,&head);
	for(int i=0;i<N;i++){
		Node node;
		scanf("%d%d%d",&node.address,&node.data,&node.next);
		list[node.address].push_back(node);
	}
	if(head==-1){
		printf("%d %d\n",-1,0);
		return 0;
	}
	else{
	int count=1;
	l.push_back(list[head][0]);
	while(true){
		int next=list[head][0].next;
		if(next==-1)
			break;
		else{
			l.push_back(list[next][0]);
			head=next;
			count++;
		}
	}
	sort(l.begin(),l.end(),cmp);
	printf("%d %05d\n",count,l[0].address);
	for(vector<Node>::iterator it=l.begin();it!=l.end();it++){
		if((it+1)==l.end())
			printf("%05d %d %d\n",(*it).address,(*it).data,-1);
		else
			printf("%05d %d %05d\n",(*it).address,(*it).data,(*(it+1)).address );
	}
	return 0;
}
}