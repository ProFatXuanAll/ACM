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

#define MAX (100+1)

struct point{
	double x;
	double y;
};

static struct point gopher[MAX], hole[MAX];
static bool G[MAX][MAX], visit[MAX];
static int llink[MAX], rlink[MAX];
static bool DFS(int v,int m);

int main(void)
{
	int n, m, s, v;
	int i, j, ans;
	double dis, sdis;

	while(scanf("%d%d%d%d",&n,&m,&s,&v)!=EOF)
	{

		sdis=v*s;
		ans=0;

		for(i=0;i<n;++i)
			scanf("%lf%lf",&gopher[i].x,&gopher[i].y);
		
		for(i=0;i<m;++i)
			scanf("%lf%lf",&hole[i].x,&hole[i].y);
	
		for(i=0;i<n;++i)
			for(j=0;j<m;++j)
			{
				dis=sqrt(pow(gopher[i].x-hole[j].x,2)+pow(gopher[i].y-hole[j].y,2));
				if(dis<=sdis)
					G[i][j]=true;
				else
					G[i][j]=false;
			}
	
		memset(llink,-1,sizeof(int)*n);
		memset(rlink,-1,sizeof(int)*m);

		for(int i=0;i<n;++i)
		{
			memset(visit,false,sizeof(bool)*m);
			if(DFS(i,m))
				ans++;
		}

		printf("%d\n",n-ans);
	}

	return 0;
}

static bool DFS(int v,int m)
{
	int i;

	for(i=0;i<m;++i)
	{
		if(!G[v][i]||visit[i])
			continue;

		visit[i]=true;

		if(rlink[i]==-1||DFS(rlink[i],m))
		{
			llink[v]=i;
			rlink[i]=v;
			return true;
		}
	}

	return false;
}
