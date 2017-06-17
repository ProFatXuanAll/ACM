#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn (100+1)
#define maxm (64)

unsigned long long a[maxn][maxm];

int n;
unsigned long long h;

int main()
{
    for(int i = 1; i < maxn; i++)
        for(int j = 1; j < maxm; j++)
            a[i][j] = a[i-1][j-1] + 1 + a[i][j-1];

    while(scanf("%d%llu",&n,&h) && n)
    {
        int i;
        for(i = 1; i < maxm; i++) 
			if(a[n][i] >= h) 
				break;

        if(i < maxm) 
			printf("%d\n", i);
        else 
			puts("More than 63 trials needed.");
    }

    return 0;
}
