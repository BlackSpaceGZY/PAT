#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Customer{
	int gt,pt;
};
int cmp(Customer c1,Customer c2){
	return c1.gt<c2.gt;
}
int findMin(int w[],int len){
	int index=0;
	for(int i=1;i<len;i++)
		if(w[index]>w[i])
			index=i;
	return index;
}
int main(){
	int cs,windows,hh,mm,ss,pt,second,index;
	float time=0;
	char ch;
	vector<Customer>v;
	cin>>cs>>windows;
	int win[windows];
	fill(win,win+windows,8*60*60);
	for(int i=0;i<cs;i++){
		cin>>hh>>ch>>mm>>ch>>ss>>pt;
		if(hh*3600+mm*60+ss>17*3600)
			continue;
		Customer customer;
		customer.gt=hh*3600+mm*60+ss;
		customer.pt=pt*60;
		v.push_back(customer);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		index=findMin(win,windows);
		if(win[index]>v[i].gt){
			time+=(win[index]-v[i].gt);
			win[index]+=v[i].pt;
		}
		else
			win[index]=v[i].gt+v[i].pt;
	}
	printf("%.1f\n",time/60/v.size());
	return 0;
}