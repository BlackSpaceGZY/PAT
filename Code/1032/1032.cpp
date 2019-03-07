#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int next;
	char data;
};
int main(){
	vector< vector<Node>>v(100000);
	int fa,sa,n,len1=0,len2=0,ad,i,j;
	cin>>fa>>sa>>n;
	for(i=0;i<n;i++){
		Node node;
		cin>>ad>>node.data>>node.next;
		v[ad].push_back(node);
	}
	ad=fa;
	while(ad!=-1){
		len1++;
		ad=v[ad][0].next;
	}
	ad=sa;
	while(ad!=-1){
		len2++;
		ad=v[ad][0].next;
	}
	i=fa;j=sa;
	if(len1>len2){
		for(int k=0;k<len1-len2;k++){
			i=v[i][0].next;
		}
	}
	else if(len2>len1){
		for(int k=0;k<len2-len1;k++){
			j=v[j][0].next;
		}
	}
	while(i!=j){
		i=v[i][0].next;
		j=v[j][0].next;
	}
	cout<<i<<endl;
	return 0;
}
/*
#include <cstdio>
using namespace std;
struct NODE {
    char key;
    int next;
    bool flag;
}node[100000];
int main() {
    int s1, s2, n, a, b;
    scanf("%d%d%d", &s1, &s2, &n);
    char data;
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d", &a, &data, &b);
        node[a] = {data, b, false};
    }
    for(int i = s1; i != -1; i = node[i].next)
        node[i].flag = true;
    for(int i = s2; i != -1; i = node[i].next) {
        if(node[i].flag == true) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
*/
 