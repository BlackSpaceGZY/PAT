#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

typedef struct school{
	string name;
	double grades;
	int score;
	int st;
}school;

int cmp(school s1,school s2){
	return s1.score==s2.score?s1.st==s2.st?
	s1.name<s2.name:s1.st<s2.st:s1.score>s2.score;
}
double getgrades(string s,int num){
	if(s[0]=='B')
		return num/1.5;
	if(s[0]=='A')
		return num;
	else
		return num*1.5;
}
int main(){
	int n;
	cin>>n;
	vector<school>v;
	map<string,int>m;
	int c=1;
	for(int i=0;i<n;i++){
		string s,s1;
		int num;
		cin>>s>>num>>s1;
		transform(s1.begin(),s1.end(),s1.begin(),::tolower);
		if(m[s1]==0){
			school sc;
			sc.name=s1;
			sc.st=1;
			sc.grades=getgrades(s,num);
			v.push_back(sc);
			m[s1]=c;
			c++;
		}
		else{
			v[m[s1]-1].st++;
			v[m[s1]-1].grades+=getgrades(s,num);
		}
	}
	for(int i=0;i<v.size();i++){
		v[i].score=(int)v[i].grades;
	}
	sort(v.begin(),v.end(),cmp);
	int cnt=1;
	cout<<v.size()<<endl;
	cout<<cnt<<" "<<v[0].name<<" "<<v[0].score<<" "<<v[0].st<<endl;
	for(int i=1;i<v.size();i++){
		if(v[i-1].score!=v[i].score)
			cnt=1+i;
		cout<<cnt<<" "<<v[i].name<<" "<<v[i].score<<" "<<v[i].st<<endl;
	}
	return 0;
}