#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
	int max,num,l;
	scanf("%d%d%d",&max,&num,&l);
	int a[l][num];
	bool flag=true;
	int count=0;
	for(int i=0;i<l;i++){
		for(int j=0;j<num;j++){
			scanf("%d",&a[i][j]);
			if(flag==true){
				for(int k=0;k<j;k++)
					if(a[i][k]<a[i][j])
						count++;
			    if(a[i][j]-count>max)
			    	flag=false;
			    count=0;
			    if(j>1&&a[i][j]>a[i][j-1]&&
				a[i][j-2]>a[i][j-1]&&a[i][j-2]>a[i][j])
			    	flag=false;
			}
		}
		if(!flag)
			printf("%s\n","NO");
		else
			printf("%s\n","YES");
		flag=true;
	}
	return 0;
}