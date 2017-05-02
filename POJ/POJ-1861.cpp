#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N (1000+1)
#define MAX_M (15000+1)
#define MAX_L (1000000)

struct line{
	int from;
	int to;
	int dis;
};

static int find(int set[],int x);
static bool cmp(struct line a, struct line b);

int main(void)
{
	int N, M, set[MAX_N], max, P;

	struct line graph[MAX_M];

	while(scanf("%d%d",&N,&M)!=EOF)
	{
		for(int i=0;i<M;++i)
		{
			scanf("%d%d%d",&graph[i].from,&graph[i].to,&graph[i].dis);
		}

		sort(graph,graph+M,cmp);

		memset(set,-1,sizeof(int)*N);

		vector<int>ans1,ans2;
		max=0;
		for(int i=0, count=0;i<M;++i)
		{
			if(find(set,graph[i].from)==find(set,graph[i].to))
				continue;
			else
			{
				set[find(set,graph[i].from)]=find(set,graph[i].to);
				ans1.push_back(graph[i].from);
				ans2.push_back(graph[i].to);
				if(max<graph[i].dis)
					max=graph[i].dis;
				++count;
				if(count==N-1)
					break;
			}
		}

		printf("%d\n%d\n",max,ans1.size());
		for(int i=0;i<ans1.size();++i)
		{
			printf("%d %d\n",ans1[i],ans2[i]);
		}

	}

	return 0;
}

static int find(int set[],int x)
{
	if(set[x]==-1)
		return x;
	else
	{
		return set[x]=find(set,set[x]);
	}
}

static bool cmp(struct line a, struct line b)
{
	return a.dis<b.dis;
}
