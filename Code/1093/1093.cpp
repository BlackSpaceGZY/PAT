#include<iostream>
using namespace std;

int findP(string s,int i){
	for(int j=i;j<s.length();j++)
		if(s[j]=='P')
			return j;
	return -1;
}
int findT(string s,int i){
	for(int j=i;j>=0;j--)
		if(s[j]=='T')
			return j;
	return -1;
}
int main(){
	string s;
	cin>>s;
	int i=-1,j=s.length(),count=0;
	while(true){
		j=findT(s,j-1);
		if(j==-1)
			break;
		else{
			do{
			i=findP(s,i+1);
			if(i!=-1&&i<j){
			for(int k=i+1;k<j;k++)
				if(s[k]=='A')
					count++;
			}
		}while(i!=-1&&i<j);
		i=-1;
	}
}
	printf("%d\n",count);
	return 0;
}