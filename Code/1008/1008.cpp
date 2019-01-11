#include<iostream>
using namespace std;
int main(){
	int N,e,before=0,seconds=0;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>e;
		if(e>before)
			seconds+=6*(e-before)+5;
		else
			seconds+=4*(before-e)+5;
		before=e;
	}
	cout<<seconds;
	return 0;
}