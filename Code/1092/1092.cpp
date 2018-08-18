#include<iostream>
using namespace std;

int main(){
	string s1,s2;
	int count=0;
	cin>>s1>>s2;
	int hash[255]={0};
	for(int i=0;i<s1.length();i++)
		hash[s1[i]]++;
	for(int i=0;i<s2.length();i++){
		if(hash[s2[i]]==0)
			count++;
		else
			hash[s2[i]]--;
	}
	if(count!=0)
		printf("No %d\n",count);
	else
		printf("Yes %d\n",s1.length()-s2.length());
	return 0;
}