#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_S (100)
#define MAX_P (500)

struct point{
	int x;
	int y;
};

struct line{
	int from;
	int to;
	double dis;
};

static inline double sq(double a);
static bool cmp(struct line a,struct line b);
static int find(int set[],int x);

int main(void)
{
	int N, S, P, set[MAX_P], top;
	double ans;

	struct point stack[MAX_P];
	struct line graph[MAX_P*MAX_P];

	scanf("%d",&N);

	while(N--)
	{
		scanf("%d%d",&S,&P);

		top=0;
		for(int i=0;i<P;++i)
		{
			scanf("%d%d",&stack[i].x,&stack[i].y);
			for(int j=i-1;j>=0;--j)
			{
				graph[top].from=i;
				graph[top].to=j;
				graph[top].dis=sqrt(sq((double)(stack[i].x-stack[j].x))+sq((double)(stack[i].y-stack[j].y)));
				++top;
			}
		}

		sort(graph,graph+top,cmp);

		memset(set,-1,sizeof(set));
		ans=0.0f;

		for(int i=0, count=0;i<top;++i)
		{
			if(find(set,graph[i].from)==find(set,graph[i].to))
				continue;
			else
			{
				set[find(set,graph[i].from)]=find(set,graph[i].to);
				ans=graph[i].dis;
				++count;
				if(count>=P-S)
					break;
			}
		}

		printf("%.2f\n",ans);
	}

	return 0;
}

static inline double sq(double a)
{
	return a*a;	
}

static bool cmp(struct line a,struct line b)
{
	return a.dis<b.dis;
}

static int find(int set[],int x)
{
	if(set[x]==-1)
		return x;
	else
		return set[x]=find(set,set[x]);
}
