#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

#define MAX (100000+1)

static long long int A[MAX], s[MAX], N;

static long long int lowbit(long long int index)
{
	return index&(-index);
}

static long long int getsum(long long int index)
{
	long long int res=0;

	while(index>0)
	{
		res+=s[index];
		index-=lowbit(index);
	}

	return res;
}

static void modify(long long int index, long long int diff)
{
	while(index<=N)
	{
		s[index]+=diff;
		index+=lowbit(index);
	}
}

int main(void)
{
	long long int Q;
	long long int a, b, c;
	char C;

	while(scanf("%lld %lld ",&N,&Q)!=EOF)
	{
		memset(s+1,0,sizeof(long long int)*N);
		for(long long int i=1;i<=N;++i)
		{
			scanf("%lld ",&A[i]);
			modify(i,A[i]);
		}
		
		for(long long int i=0;i<Q;++i)
		{
			scanf("%c ",&C);
			if(C=='Q')
			{
				scanf("%lld %lld ",&a,&b);
				printf("%lld\n",getsum(b)-getsum(a-1));
			}
			else
			{
				scanf("%lld %lld %lld ",&a,&b,&c);
				for(long long int j=a;j<=b;++j)
					modify(j,c);
			}
		}
	}

	return 0;
}
