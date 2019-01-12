#include<iostream>
#include<cmath>
#include<cctype>
using namespace std;
long long compute(string s,int radix){
	long long num=0;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i]))
			num+=(s[i]-'0')*pow(radix,s.length()-i-1);
		else
			num+=(s[i]-'a'+10)*pow(radix,s.length()-i-1);
	}
	return num;
}
int main(){
	string N1,N2;
	int tag,radix;
	long long num1=0,low=0,high=0,mid;
	cin>>N1>>N2>>tag>>radix;
	if(tag==2)
		swap(N1,N2);
	num1=compute(N1,radix);
	for(int i=0;i<N2.length();i++){
		if(isdigit(N2[i]))
			if(low<N2[i]-'0')
				low=N2[i]-'0'+1;
		else
			if(low<N2[i]-'a')
				low=N2[i]-'a'+1;
	}
	high=max(num1,low);
	while(low<=high){
		mid=(low+high)/2;
		long long t = compute(N2,mid);
		if(t>num1||t<0)
			high=mid-1;
		else if(t==num1){
			cout<<mid;
			return 0;
		}
		else
			low=mid+1;
	}
	cout<<"Impossible";
	return 0;
}