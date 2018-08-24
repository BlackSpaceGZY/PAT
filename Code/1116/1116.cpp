#include<iostream>
using namespace std;

bool isprime(int num){
	for(int i=2;i*i<=num;i++)
		if(num%i==0)
			return false;
	return true;
}
int main(){
	int arra[10000]={0},N,q;
	bool flag[10000]={false};
	cin>>N;
	for(int i=1;i<=N;i++){
		int index;
		cin>>index;
		arra[index]=i;
		flag[index]=true;
	}
	cin>>q;
	for(int i=0;i<q;i++){
		int num;
		cin>>num;
		if(arra[num]==0)
			printf("%04d: Are you kidding?\n",num);
		else if(arra[num]!=0&&flag[num]==false)
			printf("%04d: Checked\n",num );
		else if(arra[num]==1)
			printf("%04d: Mystery Award\n",num );
		else if(isprime(arra[num])==true)
			printf("%04d: Minion\n",num );
		else
			printf("%04d: Chocolate\n",num );
		flag[num]=false;
	}
	return 0;
}