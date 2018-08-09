#include<iostream>
using namespace std;

int main(){
	int data[100001],next[100001],list[100001],result[100001];
	int start,temp,n,k,sum=0;
	cin>>start>>n>>k;
	for(int i=0;i<n;i++){
		cin >> temp;
        cin >> data[temp] >> next[temp];
	}
	while(start!=-1){
		list[sum++]=start;
		start=next[start];
	}
	for(int i=0;i<sum;i++)
		result[i]=list[i];
	for (int i=0;i<(sum-sum%k);i++)   //有几个元素是需要置换的
        result[i]=list[i/k*k+k-1-i%k];  //第几组+(k-1-i%k)
    for (int i=0;i<sum-1;i++)
        printf("%05d %d %05d\n",result[i],data[result[i]],result[i + 1]);
    printf("%05d %d -1", result[sum - 1], data[result[sum - 1]]);
	return 0;
}