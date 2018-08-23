#include<iostream>
using namespace std;

int main(){
	int k,arr[256]={0};
	cin>>k;
	string s;
	cin>>s;
	int count=1;
	for(int i=0;i<s.length()-1;i++){
		if(s[i]==s[i+1]){
			count++;
			if(count!=k){
				continue;
			}
			else{
				if(arr[s[i]]==-1){
					count=1;
					i++;
					continue;
				}
				arr[s[i]]=1;
				i++;
				count=1;
			}
		}
		else{
			arr[s[i]]=-1;
			count=1;
		}
	}
	char c[255];
	int j=0;
	for(int i=0;i<256;i++){
		if(arr[i]==1){
			char c1=i;
			c[j++]=c1;
			cout<<c1;
		}
	}
	if(j!=0)
		cout<<endl;
	for(int i=0;i<j;i++){
		int pos=s.find(c[i]);
		while(pos!=-1){
			string s1="0";
			s1[0]=c[i];
			s.replace(pos,k,s1);
			pos=s.find(s1,pos+1);
		}
	}
	cout<<s;
	return 0;
}