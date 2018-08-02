#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef struct{
	int data[100001];
	int top;
}Stack;

void push(Stack &st,int K){
	st.top++;
	st.data[st.top]=K;
}

int pop(Stack &st){
	if(st.top==-1)
		return -1;
	else
		return st.data[st.top--];
}

int peekMedian(Stack &st){
	if(st.top==-1)
		return -1;
	else{
		int a[st.top+1];
		for(int i=0;i<=st.top;i++)
			a[i]=st.data[i];
		sort(a,a+st.top+1);
		return a[st.top/2];
	}
}
int main(){
	int N;
	scanf("%d",&N);
	Stack st;
	st.top=-1;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		if(s=="Push"){
			int data;
			cin>>data;
			push(st,data);
		}
		else if(s=="Pop"){
			int flag=pop(st);
			if(flag==-1)
				printf("%s\n","Invalid");
			else
				printf("%d\n",flag);
		}
		else if(s=="PeekMedian"){
			int flag=peekMedian(st);
			if(flag==-1)
				printf("%s\n","Invalid");
			else
				printf("%d\n",flag);
		}
	}
	return 0;
}