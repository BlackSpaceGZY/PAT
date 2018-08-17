#include<iostream>
#include<cmath>
using namespace std;

long int gcd(long int n,long int d){
	if(n<0)
		n=abs(n);
	return d==0?n:gcd(d,n%d);
}
void help(long int n,long int d){
	if(n==0){
		printf("0");
		return ;
	}
	if(n<0)
		printf("(");
	if(abs(n)>=d){
		printf("%d",n/d);
		if(abs(n)%d!=0)
		printf(" %d/%d",abs(n)%d,d);
	}
	else
		printf("%d/%d",n,d);
	if(n<0)
		printf(")");
}
int main(){
	long int n1,d1,n2,d2,n3,d3,f1,f2,f3;
	char c1,c2;
	cin>>n1>>c2>>d1>>n2>>c2>>d2;
	f1=gcd(n1,d1);
	f2=gcd(n2,d2);
	n1/=f1;
	d1/=f1;
	n2/=f2;
	d2/=f2;
	for(int i=0;i<4;i++){
		help(n1,d1);
		switch(i){
			case 0:
				printf(" + ");
				n3=n1*d2+n2*d1;
				d3=d1*d2;
				break;
			case 1:
			 	printf(" - ");
			 	n3=n1*d2-n2*d1;
				d3=d1*d2;
				break;
			case 2:
				printf(" * ");
				n3=n1*n2;
				d3=d1*d2;
				break;
			case 3:
				printf(" / ");
				n3=n1*d2;
				d3=d1*n2;
				if(n2<0){
					n3*=-1;
					d3*=-1;
				}
				break;
		}
		help(n2,d2);
		f3=gcd(n3,d3);
		n3/=f3;
	    d3/=f3;
		printf(" = ");
		if(i==3&&d3==0)
			printf("Inf");
		else
			help(n3,d3);
		printf("\n");
	}
	return 0;
}