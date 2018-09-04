#include<iostream>
using namespace std;

int main(){
    int n;
    float num1[1002]={0};
    for(int i=0;i<2;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int a;
            float b;
            cin>>a>>b;
            num1[a]+=b;
        }
    }
    int cnt=0;
    for(int i=1001;i>=0;i--){
    	if(num1[i]!=0)
    		cnt++;
    }
    cout<<cnt;
    for(int i=1001;i>=0;i--){
        if(num1[i]!=0)
            printf(" %d %.1f",i,num1[i]);
    }
    return 0;
}
