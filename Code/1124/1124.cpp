#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N,skip,first,count=1;
	vector<string>v;
	cin>>N>>skip>>first;
	if(first>N){
		for(int i=1;i<=N;i++){
			string s;
			cin>>s;
		}
		cout<<"Keep going...";
	}
	else{
		for(int i=1;i<=N;i++){
			string s;
			cin>>s;
			if(first==i){
				v.push_back(s);
				cout<<s<<endl;
			}
			else if(i>first&&count==skip){
				int j=0;
				for(;j<v.size();j++){
					if(v[j]==s)
						break;
				}
				if(j!=v.size())
					continue;
				else{
					v.push_back(s);
					cout<<s<<endl;
					count=1;
				}
			}
			else if(i>first&&count!=skip)
				count++;
		}
	}
	return 0;
}