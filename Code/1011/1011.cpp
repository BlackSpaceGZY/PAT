#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double a,b,c,maxs=1;
	for(int i=0;i<3;i++){
		cin>>a>>b>>c;
		if(a>b&&a>c)
			cout<<"W ";
		else if(max(a,max(b,c))==b)
			cout<<"T ";
		else
			cout<<"L ";
		maxs*=max(a,max(b,c));
	}
	printf("%.2f",(maxs*0.65-1)*2);
	return 0;
}