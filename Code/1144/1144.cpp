#include<iostream>
#include<set>
using namespace std;

int main(){
	set<int>s;
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		if(a<=0)
			continue;
		s.insert(a);
	}
	set<int>::iterator it=s.begin();
	int i=1;
	for(;i<=s.size();i++){
		if(i!=*(it)){
			cout<<i;
			break;
		}
		it++;
	}
	if(i==s.size()+1)
		cout<<i;
	return 0;
}