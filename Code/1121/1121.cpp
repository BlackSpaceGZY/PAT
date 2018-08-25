#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int N,M,couples[100000];
	memset(couples,-1,sizeof couples);
	cin>>N;
	for(int i=0;i<N;i++){
		int a,b;
		cin>>a>>b;
		couples[a]=b;
		couples[b]=a;
	}
	cin>>M;
	vector<int> v;
	vector<int> v1;
	for(int i=0;i<M;i++){
		int a;
		cin>>a;
		v1.push_back(a);
	}
	for(int i=0;i<v1.size();i++){
		if(couples[v1[i]]==-1){
			v.push_back(v1[i]);
			continue;
		}
		bool flag=true;
		for(int j=i+1;j<v1.size();j++){
			if(couples[v1[i]]==v1[j]){
				vector<int>::iterator it=v1.begin()+j;
				v1.erase(it,it+1);
				flag=false;
				break;
			}
		}
		if(flag==true)
			v.push_back(v1[i]);
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		if(i!=0)
			cout<<" ";
		printf("%05d",v[i]);
	}
	return 0;
}