#include<iostream>
using namespace std;

int main(){
	int N,b,j=0;
	cin>>N>>b;
	int digit[10000],pos=0;
	while(N>0){
		digit[pos++]=N%b;
		N/=b;
	}
	while(j<=pos/2){
		if(digit[j]==digit[pos-1-j])
			j++;
		else
			break;
	}
	if(j<pos/2)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	cout<<digit[pos-1];
	for(int i=pos-2;i>=0;i--)
		cout<<" "<<digit[i];
	return 0;
}