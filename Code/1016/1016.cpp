#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Time{
	string time;
	string flag;
};
struct Customer{
	string name;
	vector<Time>v;
};
int cmp1(Customer c1,Customer c2){
	return c1.name<c2.name;
}
int cmp2(Time t1,Time t2){
	return t1.time<t2.time;
}
float compute(string s1,string s2,int bill[]){
	float money=0;
	if(stoi(s1.substr(9,2))!=0)
		money-=(stoi(s1.substr(9,2)))*bill[stoi(s1.substr(6,2))];
	if(stoi(s2.substr(9,2))!=0)
		money+=(stoi(s2.substr(9,2)))*bill[stoi(s2.substr(6,2))];
	for(int i=0;i<stoi(s1.substr(6,2));i++)
		money-=bill[i]*60;
	for(int i=0;i<stoi(s2.substr(6,2));i++)
		money+=bill[i]*60;
	for(int i=0;i<24;i++)
		money+=(stoi(s2.substr(3,2))-stoi(s1.substr(3,2)))*bill[i]*60;
	return money/100;
}
int main(){
	int bill[24],k,fg,minutes;
	string name,t1,t2;
	float money=0,total=0;
	vector<Customer>v1;
	for(int i=0;i<24;i++)
		cin>>bill[i];
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>name;
		Time t;
		cin>>t.time>>t.flag;
		int j=0;
		for(;j<v1.size();j++)
			if(name==v1[j].name)
				break;
		if(j==v1.size()){
			Customer c;
			c.name=name;
			c.v.push_back(t);
			v1.push_back(c);
		}
		else
			v1[j].v.push_back(t);
	}
	sort(v1.begin(),v1.end(),cmp1);
	for(int i=0;i<v1.size();i++){
	  printf("%s %s\n",v1[i].name.c_str(),
	 		v1[i].v[0].time.substr(0,2).c_str());
	 	sort(v1[i].v.begin(),v1[i].v.end(),cmp2);
	 	fg=0;
		for(int j=0;j<v1[i].v.size();j++){
			if(v1[i].v[j].flag=="on-line"){
				t1=v1[i].v[j].time;
				fg=1;
			}
			else if(fg==1&&v1[i].v[j].flag=="off-line"){
				t2=v1[i].v[j].time;
				fg=0;
				minutes=stoi(t2.substr(3,2))*60*24+stoi(t2.substr(6,2))*60
				+stoi(t2.substr(9,2))-stoi(t1.substr(3,2))*60*24
				-stoi(t1.substr(6,2))*60-stoi(t1.substr(9,2));
				money=compute(t1,t2,bill);
				total+=money;
				printf("%s %s %d $%.2f\n",t1.substr(3).c_str(),t2.substr(3).c_str()
					,minutes,money);
			}
		}
		printf("Total amount: $%.2f\n",total);
		total=0;
	}
	return 0;
}