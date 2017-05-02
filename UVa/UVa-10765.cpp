#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX (10000)

struct pigeon{
	int index;
	int value;
	bool operator < (struct pigeon& in)
	{
		return value==in.value?index>in.index:value<in.value;
	}
};

static void init(int n);
static bool visit[MAX];
static int dfn[MAX], low[MAX], t;
static vector<int> G[MAX];
static struct pigeon ans[MAX];
static void DFS(int v, int parent);
static int min(int a, int b);

int main(void)
{
	int n, m;
	int st1, st2;

	while(1)
	{
		scanf("%d%d",&n,&m);

		if(!n&&!m)
			break;

		init(n);

		while(1)
		{
			scanf("%d%d",&st1,&st2);
			
			if(st1==-1&&st2==-1)
				break;

			G[st1].push_back(st2);
			G[st2].push_back(st1);
		}
		
		for(int i=0;i<n;i++)
		{
			if(!visit[i])
			{
				DFS(i,-1);
			}
		}
		for(int i=0;i<n;i++)
		{
			if(G[i].size()!=ans[i].value)
				ans[i].value++;
		}
		sort(ans,ans+n);
		for(int i=0;i<m;i++)
		{
			printf("%d %d\n",ans[n-1-i].index,ans[n-1-i].value);
		}
		puts("");
	}


	return 0;
}

static void init(int n)
{
	for(int i=0;i<n;i++)
	{
		G[i].clear();
		visit[i]=false;
		ans[i].value=0;
		ans[i].index=i;
	}
	t=0;
}

static void DFS(int v, int parent)
{
	visit[v]=true;
	dfn[v]=low[v]=++t;

	for(int i=0;i<G[v].size();++i)
	{
		if(!visit[G[v].at(i)]) /* child */
		{
			DFS(G[v].at(i),v);
			low[v]=min(low[v],low[G[v].at(i)]);

			if(low[G[v].at(i)]>dfn[v]) /* bridge */
			{
				++ans[v].value;
				++ans[G[v].at(i)].value;
			}
		}
		else if(G[v].at(i)!=parent) /* back edge */
		{
			low[v]=min(low[v],dfn[G[v].at(i)]);
		}
	}

}

static int min(int a, int b)
{
	return a<b?a:b;
}
