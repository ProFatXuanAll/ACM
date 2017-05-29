#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX (32000+2)

static int level[MAX], s[MAX];
static int lowbit(int x);
static int getsum(int x);
static void modify(int x,int diff);

int main(void)
{
	int n, x, y;

	while(scanf("%d",&n)!=EOF)
	{
		memset(level,0,sizeof(level));
		memset(s,0,sizeof(s));

		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&x,&y);
			++x;
			++level[getsum(x)];
			modify(x,1);
		}
		for(int i=0;i<n;++i)
			printf("%d\n",level[i]);
	}

	return 0;
}

static int lowbit(int x)
{
	return x & (-x);
}

static int getsum(int x)
{
	int res=0;
	while(x>0)
	{
		res+=s[x];
		x-=lowbit(x);
	}
	return res;
}

static void modify(int x,int diff)
{
	while(x<MAX)
	{
		s[x]+=diff;
		x+=lowbit(x);
	}
}
