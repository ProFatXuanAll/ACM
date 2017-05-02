#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX_N (1000+1)

struct graph{
	int to[MAX_N];
	int count;
};

static struct graph G[MAX_N];

static void init(int n);
static int min(int a, int b);

static bool visit[MAX_N];
static int t;
static int dfn[MAX_N];
static int low[MAX_N];
static void DFS(int v, int parent);

int main(void)
{
	int n, m;
	int to, from;
	int cases=1;

	while(1)
	{
		scanf("%d%d",&n,&m);

		if(n==0&&m==0)
			break;

		init(n);

		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&from,&to);
			G[from].to[G[from].count]=to;
			G[to].to[G[to].count]=from;
			G[from].count++;
			G[to].count++;
		}

		printf("%d\n\n",cases++);
		DFS(1,-1);
		printf("#\n");

	}

	return 0;
}

static void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		G[i].count=0;
		visit[i]=false;
	}
	t=1;
}

static void DFS(int v, int parent)
{
	visit[v]=true;
	low[v]=dfn[v]=t++;

	for(int i=0;i<G[v].count;i++)
	{
		if(!visit[G[v].to[i]]) /* child */
		{
			DFS(G[v].to[i],v);
			low[v]=min(low[v],low[G[v].to[i]]);
			printf("%d %d\n",v,G[v].to[i]);
			if(low[G[v].to[i]]>dfn[v])
			{
				printf("%d %d\n",G[v].to[i],v); /* articulation point */
			}
		}
		else if(G[v].to[i]!=parent) /* back edge */
		{
			if(dfn[v]>dfn[G[v].to[i]])
			{
				printf("%d %d\n",v,G[v].to[i]);
			}

			low[v]=min(low[v],dfn[G[v].to[i]]);
		}
	}
}

static int min(int a, int b)
{
	return a<b?a:b;
}
