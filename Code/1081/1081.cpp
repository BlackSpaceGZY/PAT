#include<iostream>
using namespace std;


long long find(long  a,long long b){
	if(a<b){
		long long temp=a;
		a=b;
		b=temp;
	}
	int r;
	if(a%b==0)
		return b;
	do{
		r=a%b;
		a=b;
		b=r;
	}while((a%b)!=0);
	return r;
}
int main(){
	long long N,num=0,den=0;
	char c;
	cin>>N;
	for(int i=0;i<N;i++){
		long long temp1,temp2,t;
		cin>>temp1>>c>>temp2;
		if(temp1!=0){
			t=find(temp1,temp2);
			temp1/=t;
			temp2/=t;
		}
		if(num==0){
			num=temp1;
			den=temp2;
		}
		else{
			num=num*temp2+den*temp1;
			den=den*temp2;
			if(num==0)
				continue;
			long long r=find(num,den);
			num/=r;
			den/=r;
		}
	}
	if(num==0)
		cout<<0;
	else{
		if(num/den!=0)
			cout<<num/den;
		if(num/den!=0&&num%den!=0)
			cout<<" ";
		if(num%den!=0)
			cout<<num-(num/den)*den<<"/"<<den;
	}
	return 0;
}