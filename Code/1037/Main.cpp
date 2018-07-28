#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int NC;
	scanf("%d",&NC);
	int nc[NC];
	for(int i=0;i<NC;i++)
		scanf("%d",&nc[i]);
	int NP;
	scanf("%d",&NP);
	int np[NP];
	for(int i=0;i<NP;i++)
		scanf("%d",&np[i]);
	sort(nc,nc+NC);
	sort(np,np+NP);
	int max=0;
    int i=0,j=0,k=NC-1,l=NP-1;
    while (nc[i]<0&&np[j]<0&&i<NC&&j<NP){
        max+=nc[i]*np[j];
        i++;
        j++;
    }
    while (nc[k]>0&&np[l]>0&&k>=0&&l>=0){
        max+=nc[k]*np[l];
        k--;
        l--;
    }
    printf("%d\n",max );
	return 0;
}