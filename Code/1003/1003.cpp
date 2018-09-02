#include <iostream>
#include<vector>
using namespace std;

vector< vector<int> >v;
vector<int>v1;
vector<int>visit;
int minlength=10000;
int maxsum=0;
int count=0;

void dj(int start,int last,int len,int sum){
    if(start==last){
        if(len<minlength){
            minlength=len;
            maxsum=sum;
            count=1;
        }
        else if(len==minlength){
            maxsum=maxsum>sum?maxsum:sum;
            count++;
        }
        return;
    }
    else{
        for(int i=0;i<v[0].size();i++){
            if(visit[i]==0&&v[start][i]!=0){
                visit[i]=1;
                dj(i,last,len+v[start][i],sum+v1[i]);
                visit[i]=0;
            }
        }
    }
}
int main()
{
    int N,M,start,last;
    cin>>N>>M>>start>>last;
    v.resize(N,vector<int>(N,0));
    visit.resize(N,0);
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v1.push_back(a);
    }
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a][b]=v[b][a]=c;
    }
    visit[start]=1;
    dj(start,last,0,v1[start]);
    cout<<count<<" "<<maxsum;
    return 0;
}
