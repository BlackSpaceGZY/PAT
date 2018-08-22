#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int level=0;
void bfs(vector<int>v[],double m,double r){
	int que[100001],rear=0,front=0,count=1,num;
	que[++rear]=0;
	while(rear!=front){
		while((count--)>0){
			num=que[++front];
			if(v[num].size()==0){
				printf("%.4f ",m*pow(1+r/100,level));
				int member=1;
				while((count--)>0){
					if(v[que[++front]].size()==0)
						member++;
				}
				printf("%d\n",member);
				return ;
			}
			for(int i=0;i<v[num].size();i++){
				que[++rear]=v[num][i];
			}
		}
		count=rear-front;
		level++;
	}
}
int main(){
	int N;
	double m,r;
	cin>>N>>m>>r;
	vector<int>v[N];
	for(int i=0;i<N;i++){
		int number;
		cin>>number;
		for(int j=0;j<number;j++){
			int next;
			cin>>next;
			v[i].push_back(next);
		}
	}
	bfs(v,m,r);
	return 0;
}
/*
#include<iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v[100005];
int mindepth = 99999999, minnum = 1;
void dfs(int index, int depth) {
    if(mindepth < depth)
        return ;
    if(v[index].size() == 0) {
        if(mindepth == depth)
            minnum++;
        else if(mindepth > depth) {
            mindepth = depth;
            minnum = 1;
        }
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
int main() {
    int n, k, c;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[i].push_back(c);
        }
    }
    dfs(0, 0);
    printf("%.4f %d", p * pow(1 + r/100, mindepth), minnum);
    return 0;
}
 */