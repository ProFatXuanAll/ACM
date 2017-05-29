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

#define MAX (100)

static vector<int> G[MAX];
static bool visit[MAX];
static int llink[MAX], rlink[MAX];
static bool DFS(int v);

int main(void)
{
	int n, m, k;	
	int i, x, y, ans;

	while(scanf("%d%d%d",&n,&m,&k)==3)
	{
		for(i=0;i<n;++i)
			G[i].clear();
		
		ans=0;

		for(i=0;i<k;++i)
		{
			scanf("%*d%d%d",&x,&y);
			if(!x||!y)
				continue;
			G[x].push_back(y);
		}

		memset(llink,-1,sizeof(int)*n);
		memset(rlink,-1,sizeof(int)*m);

		for(i=0;i<n;++i)
		{
			memset(visit,false,sizeof(bool)*m);
			if(DFS(i))
				++ans;
		}

		printf("%d\n",ans);
	}

	return 0;
}

static bool DFS(int v)
{
	for(int i=0;i<G[v].size();++i)
	{
		if(visit[G[v][i]])
			continue;

		visit[G[v][i]]=true;

		if(rlink[G[v][i]]==-1||DFS(rlink[G[v][i]]))
		{
			rlink[G[v][i]]=v;
			llink[v]=G[v][i];
			return true;
		}
	}

	return false;
}
