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

#define MAX (100000+10)

struct range
{
	int s;
	int e;
	int id;
};

static int N, s[MAX];
static range cow[MAX];
static int top;

static int lowbit(int index)
{
	return index&(-index);
}

static int getsum(int index)
{
	int res=0;

	while(index>0)
	{
		res+=s[index];
		index-=lowbit(index);
	}

	return res;
}

static void modify(int index, int diff)
{
	while(index<=top)
	{
		s[index]+=diff;
		index+=lowbit(index);
	}
}

static bool cmp(struct range a, struct range b)
{
	if(a.e==b.e)
		return a.s<b.s;
	else
		return a.e>b.e;
}

int main(void)
{
	int count, ans[MAX];
	range pre;

	while(1)
	{
		scanf("%d",&N);

		if(!N)
			break;

		memset(s,0,sizeof(s));
		top=0;

		for(int i=0;i<N;++i)
		{
			scanf("%d%d",&cow[i].s,&cow[i].e);
			++cow[i].s;
			++cow[i].e;
			cow[i].id=i;
			top=max(top,cow[i].s);
		}
		
		sort(cow,cow+N,cmp);

		count=0;
		pre.e=pre.s=-1;

		for(int i=0;i<N;++i)
		{
			if(cow[i].s==pre.s&&cow[i].e==pre.e)
				++count;
			else
			{
				count=0;
				pre.s=cow[i].s;
				pre.e=cow[i].e;
			}

			ans[cow[i].id]=getsum(cow[i].s)-count;
			modify(cow[i].s,1);
		}

		for(int i=0;i<N;++i)
			printf("%d ",ans[i]);
		puts("");

	}

	return 0;
}
