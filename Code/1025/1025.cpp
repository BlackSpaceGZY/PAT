#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct student{
	string id;
	int final_rank,location_number,local_rank,score;
};
int cmp(student s1,student s2){
	if(s1.score==s2.score)
		return s1.id<s2.id;
	else
		return s1.score>s2.score;
}
int main(){
	int n,m,pos=0;
	cin>>n;
	vector<student>v;
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int j=0;j<m;j++){
			student st;
			cin>>st.id>>st.score;
			st.location_number=i;
			v.push_back(st);
		}
		sort(v.begin()+pos,v.begin()+pos+m,cmp);
		v[pos].local_rank=1;
		for(int j=pos+1;j<pos+m;j++){
			if(v[j].score==v[j-1].score)
				v[j].local_rank=v[j-1].local_rank;
			else
				v[j].local_rank=j-pos+1;
		}
		pos=v.size();
	}
	sort(v.begin(),v.end(),cmp);
	cout<<v.size()<<endl;
	v[0].final_rank=1;
	for(int i=1;i<v.size();i++){
		if(v[i].score==v[i-1].score)
			v[i].final_rank=v[i-1].final_rank;
		else
			v[i].final_rank=i+1;
	}
	for(int i=0;i<v.size();i++)
		cout<<v[i].id<<" "<<v[i].final_rank<<
	" "<<v[i].location_number<<" "<<v[i].local_rank<<endl;
	return 0;
}