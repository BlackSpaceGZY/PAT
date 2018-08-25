#include<iostream>
using namespace std;

int main(){
	int N,count=0;
	cin>>N;
	int nums[40]={0};
	for(int i=0;i<N;i++){
		string s;
		int num=0;
		cin>>s;
		for(int j=0;j<s.length();j++)
			num+=(s[j]-'0');
		if(nums[num]==0)
			count++;
		nums[num]=1;
	}
	bool flag=true;
	cout<<count<<endl;
	for(int i=0;i<40;i++){
		if(nums[i]==1&&flag==true){
			cout<<i;
			flag=false;
		}
		else if(nums[i]==1)
			cout<<" "<<i;
	}
	return 0;
}