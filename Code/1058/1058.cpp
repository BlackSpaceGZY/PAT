#include<iostream>
#include<string>
using namespace std;
 
 
int main()
{	
	int a[3],b[3];
	char c;
	cin>>a[0]>>c>>a[1]>>c>>a[2];
	cin>>b[0]>>c>>b[1]>>c>>b[2];
	int ff=0;
	a[2]=a[2]+b[2];
	if(a[2]>=29){
		a[1]++;
		a[2]-=29;
	}
	a[1]=a[1]+b[1];
	if(a[1]>=17){
		a[0]++;
		a[1]-=17;
	}
	a[0]=a[0]+b[0];
	cout<<a[0]<<"."<<a[1]<<"."<<a[2];
 
 
	return 0;
}