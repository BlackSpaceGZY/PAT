#include<iostream>
using namespace std;

bool isPrime(int size){
	if(size==1)
		return false;
	for(int i=2;i*i<=size;i++)
		if(size%i==0)
			return false;
	return true;
}

void fun(int &size){
	while(isPrime(size)==false)
		size++;
}
bool hashTable[10010];
int main(){
	int size,N,temp;
	cin>>size>>N;
	fun(size);
	for(int i=0;i<N;i++){
		cin>>temp;
		int pos=temp%size;
		if(hashTable[pos]==false){
			hashTable[pos]=true;
			if(i!=0)
				printf(" ");
			printf("%d",pos);
		}
		else{
			int flag=0;
			for(int j=1;j<size;j++){
				pos=(temp+j*j)%size;
				if(hashTable[pos]==false){
					hashTable[pos]=true;
					flag=1;
					if(i!=0)
						printf(" ");
					printf("%d",pos);
					break;
				}
			}
			if(flag==0){
				if(i!=0)
					printf(" ");
				printf("-");
			}
		}
	}
	return 0;
}