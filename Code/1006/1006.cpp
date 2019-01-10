#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct student{
	string s;
	int start;
	int end;
};
int cmp1(student s1,student s2){
	return s1.start<s2.start;
}
int cmp2(student s1,student s2){
	return s1.end>s2.end;
}
int main(){
	vector<student>v;
	int M,a,b,c;
	char ch;
	string s;
	cin>>M;
	for(int i=0;i<M;i++){
		struct student st;
		cin>>st.s;
		cin>>a>>ch>>b>>ch>>c;
		st.start=a*3600+b*60+c;
		cin>>a>>ch>>b>>ch>>c;
		st.end=a*3600+b*60+c;
		v.push_back(st);
	}
	sort(v.begin(),v.end(),cmp1);
	cout<<v[0].s<<" ";
	sort(v.begin(),v.end(),cmp2);
	cout<<v[0].s;
	return 0;
}