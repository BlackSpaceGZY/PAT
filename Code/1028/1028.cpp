#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct student{
	int id,grade;
	string name;
};
int cmp1(student s1,student s2){
		return s1.id<s2.id;
}
int cmp2(student s1,student s2){
	if(s1.name==s2.name)
		return s1.id<s2.id;
	else
		return s1.name<s2.name;
}
int cmp3(student s1,student s2){
	if(s1.grade==s2.grade)
		return s1.id<s2.id;
	else
		return s1.grade<s2.grade;	
}
int main(){
	int n,c;
	vector<student>v;
	cin>>n>>c;
	for(int i=0;i<n;i++){
		student st;
		cin>>st.id>>st.name>>st.grade;
		v.push_back(st);
	}
	if(c==1)
		sort(v.begin(),v.end(),cmp1);
	else if(c==2)
		sort(v.begin(),v.end(),cmp2);
	else
		sort(v.begin(),v.end(),cmp3);
	for(int i=0;i<v.size();i++)
		printf("%06d %s %d\n",v[i].id,v[i].name.c_str(),v[i].grade);
	return 0;
}