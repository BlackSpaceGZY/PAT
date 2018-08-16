#include<iostream>
using namespace std;


void post(int pre[],int in[],int l1,int r1,int l2,int r2){
	if(l1>r1)
		return;
	int i;
	for(i=l2;i<=r2;i++)
		if(in[i]==pre[l1])
			break;
	post(pre,in,l1+1,l1+i-l2,l2,i-1);
	post(pre,in,l1+i-l2+1,r1,i+1,r2);
	if(l1!=0)
		printf("%d ",pre[l1]);
	else
		printf("%d",pre[l1]);
}
int main(){
	int N,n,j=0,k=0,top=-1;
	cin>>N;
	int pre[N],in[N],data[N];
	for(int i=0;i<2*N;i++){
		string s;
		cin>>s;
		if(s=="Push"){
			cin>>n;
			data[++top]=n;
			pre[j++]=n;
		}
		if(s=="Pop"){
			in[k++]=data[top];
			top--;
		}
	}
	post(pre,in,0,j-1,0,k-1);
	return 0;
}