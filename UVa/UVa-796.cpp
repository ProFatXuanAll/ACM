#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define MAX (1000)

struct msg{
	int from;
	int to;
	bool operator < (struct msg& in)
	{
		return from == in.from?to<in.to:from<in.from;
	}
};

static void init(int n);
static vector<int> G[MAX];
static bool visit[MAX];
static int dfn[MAX], low[MAX], t;
static void DFS(int v, int parent);
static vector<struct msg> message;
static int min(int a,int b);

int main(void)
{
	int n, from, count, to;

	while(scanf("%d ",&n)!=EOF)
	{
		init(n);

		for(int i=0;i<n;i++)
		{
			scanf("%d (%d) ",&from,&count);
			for(int j=0;j<count;j++)
			{
				scanf("%d ",&to);
				G[from].push_back(to);
			}
			sort(G[from].begin(),G[from].end());
		}
		
		for(int i=0;i<n;i++)
		{
			if(!visit[i])
			{
				DFS(i,-1);
			}
		}

		cout << message.size() << " critical links" << endl;
		sort(message.begin(),message.end());
		for(int i=0;i<message.size();i++)
		{
			struct msg tmp=message.at(i);
			cout << tmp.from << " - " << tmp.to << endl;
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
	}
	t=0;
	message.clear();
}

static void DFS(int v, int parent)
{
	visit[v]=true;
	dfn[v]=low[v]=++t;

	for(int i=0;i<G[v].size();i++)
	{
		if(!visit[G[v].at(i)]) /* child */
		{
			DFS(G[v].at(i),v);
			low[v]=min(low[v],low[G[v].at(i)]);
			if(low[G[v].at(i)]>dfn[v])
			{
				struct msg tmp;
				if(v<G[v].at(i))
				{
					tmp.from=v;
					tmp.to=G[v].at(i);
				}
				else
				{
					tmp.from=G[v].at(i);
					tmp.to=v;
				}
				message.push_back(tmp);
			}
		}
		else if(G[v].at(i)!=parent) /* back edge */
		{
			low[v]=min(low[v],dfn[G[v].at(i)]);
		}
	}
}

static int min(int a,int b)
{
	return a<b?a:b;
}
