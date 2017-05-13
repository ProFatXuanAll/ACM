#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX_T (200+1)
#define MAX_N (200+1)
#define MAX_P (40000+1)
#define MAX_LEN (1000000)

struct edge{
	int from;
	int to;
	int len;
}E[MAX_P];

static int G[MAX_N][MAX_N];
static int F[MAX_N][MAX_N];
static int visit[MAX_N];
static int pre[MAX_N];
static int MaxFlow(int N,int P,int max_len);

int main(void)
{
	int N, P, T;
	int low, high, mid, max_len;

	while(scanf("%d%d%d",&N,&P,&T)!=EOF)
	{
		max_len=0;
		for(int i=0;i<P;++i)
		{
			scanf("%d%d%d",&E[i].from,&E[i].to,&E[i].len);
			max_len=max(E[i].len,max_len);
		}

		low=0;
		high=max_len;
		while(low!=high)
		{
			mid=(low+high)/2;

			if(MaxFlow(N,P,mid)>=T)
				high=mid;
			else
				low=mid+1;
		}
		printf("%d\n",low);
	}


	return 0;
}

static int MaxFlow(int N,int P,int max_len)
{
	int tmp, ans=0;
	
	memset(G,0,sizeof(G));
	memset(F,0,sizeof(F));

	for(int i=0;i<P;++i)
	{
		if(E[i].len<=max_len)
			G[E[i].to][E[i].from]=(G[E[i].from][E[i].to]+=1);
	}

	while(1)
	{
		queue<int> q;
		q.push(1);
		memset(visit,0,sizeof(visit));
		visit[1]=INT_MAX/2;

		while(!q.empty()&&!visit[N])
		{
			tmp=q.front();
			q.pop();

			for(int i=1;i<=N;++i)
			{
				if(!visit[i]&&G[tmp][i]>F[tmp][i])
				{
					q.push(i);
					pre[i]=tmp;
					visit[i]=min(visit[tmp],G[tmp][i]-F[tmp][i]);
				}
			}
		}

		if(!visit[N])
			break;

		for(int cur=N;cur!=1;cur=pre[cur])
		{
			F[pre[cur]][cur]+=visit[N];
			F[cur][pre[cur]]-=visit[N];
		}

		ans+=visit[N];
	}

	return ans;
}

