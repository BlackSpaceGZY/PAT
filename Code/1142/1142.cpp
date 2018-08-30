#include<iostream>
#include<vector>
using namespace std;

vector< vector<int> >v;

void help(vector<int>v1){
	for(int i=0;i<v1.size();i++){
		for(int j=i+1;j<v1.size();j++){
			if(v[v1[i]][v1[j]]==0){
				cout<<"Not a Clique"<<endl;
				return;
			}
		}
	}
	for(int i=1;i<v.size();i++){
		int j=0;
		for(;j<v1.size();j++){
			if(i==v1[j])
				break;
			if(v[i][v1[j]]==0)
				break;
		}
		if(j==v1.size()){
			cout<<"Not Maximal"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
}
int main(){
	int n,e;
	cin>>n>>e;
	v.resize(210,vector<int>(210,0));
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		v[a][b]=v[b][a]=1;
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int num;
		cin>>num;
		vector<int>v1;
		for(int j=0;j<num;j++){
			int a;
			cin>>a;
			v1.push_back(a);
		}
		help(v1);
	}
	return 0;
}