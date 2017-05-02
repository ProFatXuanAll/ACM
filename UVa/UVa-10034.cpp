#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX (100)

struct line{
	int from;
	int to;
	double dis;
};

static inline double sq(double a);
static inline bool cmp(struct line a,struct line b);
static int find(int set[],int x);

int main(void)
{
	int cases, n, top;
	double ans;

	struct point{
		double x;
		double y;
	}stack[MAX];

	struct line	graph[MAX*MAX];

	int set[MAX];

	scanf("%d",&cases);

	while(cases--)
	{
		scanf("%d",&n);

		top=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&stack[i].x,&stack[i].y);
			
			for(int j=i-1;j>=0;j--)
			{
				graph[top].from=i;
				graph[top].to=j;
				graph[top].dis=sqrt(sq(stack[i].x-stack[j].x)+sq(stack[i].y-stack[j].y));
				++top;
			}
		}

		sort(graph,graph+top,cmp);

		memset(set,-1,sizeof(set));
		ans=0.0f;

		for(int i=0,count=0;i<top;i++)
		{
			if(find(set,graph[i].from)==find(set,graph[i].to))
				continue;
			else
			{
				set[find(set,graph[i].from)]=find(set,graph[i].to);
				ans+=graph[i].dis;
				++count;
				if(count==n-1)
					break;
			}
		}

		printf("%.2f\n",ans);

		if(cases)
			puts("");
	}


	return 0;
}

static inline double sq(double a)
{
	return a*a;
}

static inline bool cmp(struct line a,struct line b)
{
	return a.dis < b.dis;
}

static int find(int set[],int x)
{
	if(set[x]==-1)
		return x;
	else
		return set[x]=find(set,set[x]);
}
