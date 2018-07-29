#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
 
#define MAX 100001
int a[MAX];
int vis[MAX];
int main()
{
    int N;
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        vis[a[i]]++;
    }
    bool flag=true;
    for (int i = 0; i < N; i++)
    {
        if (vis[a[i]] == 1)
        {
            printf("%d", a[i]);
            flag=false;
            break;
        }
    }
    if (flag==true)
        printf("%s\n","None" );
    return 0;
}