#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int N;
	cin>>N;
	int arra[N];
	for(int i=0;i<N;i++)
		cin>>arra[i];
	sort(arra,arra+N);
	cout<<N%2<<" ";
	int sum=0;
	for(int i=0;i<N;i++){
		if(i<N/2)
			sum-=arra[i];
		else
			sum+=arra[i];
	}
	cout<<sum;
	return 0;

}