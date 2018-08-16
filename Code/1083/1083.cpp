#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct student{
	string name;
	string id;
	int grade;
}stu;

int cmp(stu s1,stu s2){
	return s1.grade>s2.grade;
}
int main(){
	int N;
	scanf("%d",&N);
	vector<stu> v;
	for(int i=0;i<N;i++){
		stu st;
		cin>>st.name>>st.id>>st.grade;
		v.push_back(st);
	}
	int top,bottom,count=0;
	cin>>bottom>>top;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		if(v[i].grade>top)
			continue;
		if(v[i].grade<bottom)
			break;
		else{
			count=1;
			cout<<v[i].name<<" "<<v[i].id<<endl;
		}
	}
	if(count==0)
		cout<<"NONE";
	return 0;
}