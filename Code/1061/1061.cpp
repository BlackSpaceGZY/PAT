#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;

bool isDay(char c1,char c2){
	if(65<=c1&&c1<=71&&c1==c2)
		return true;
	else
		return false;
}
int isHour(char c1,char c2){
	if((c1==c2)&&((48<=c1&&c1<=57)||(65<=c1&&c1<=78))){
		if(48<=c1&&c1<=57)
			return c1-'0';
		else
			return c1-'A'+10;
	}
	else
		return -1;
}
int main(){
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	bool flag=true;
	for(int i=0;i<min(s1.length(),s2.length());i++){
		if(flag==true&&isDay(s1[i],s2[i])){
			flag=false;
			switch(s1[i]){
				case 'A':
					cout<<"MON ";
					break;
				case 'B':
					cout<<"TUE ";
					break;
				case 'C':
					cout<<"WED ";
					break;
				case 'D':
					cout<<"THU ";
					break;
				case 'E':
					cout<<"FRI ";
					break;
				case 'F':
					cout<<"SAT ";
					break;
				case 'G':
					cout<<"SUN ";
					break;
			}
			continue;
		}
		if(flag==false&&isHour(s1[i],s2[i])>=0){
			printf("%02d:",isHour(s1[i],s2[i]));
			break;
		}
	}
	for(int i=0;i<min(s3.length(),s4.length());i++){
		if(s3[i]==s4[i]&&((65<=s3[i]&&s3[i]<=90)||(97<=s3[i]&&s3[i]<=122))){
			printf("%02d\n",i);
		}
	}
	return 0;
}