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

#define MAX_N (100+1)
#define MAX_B (1000+1)

static int B[MAX_N][MAX_N];
static int F[MAX_N][MAX_N];
static bool visit[MAX_N];
static int pre[MAX_N];
static int min_flow[MAX_N];
static int ans;

static void init(int n);
static int min(int a,int b);

int main(void)
{
	int n, s, t, c, cases=1;
	int from, to, bdw;

	while(1)
	{
		scanf("%d",&n);

		if(!n)
			break;

		init(n);
		scanf("%d%d%d",&s,&t,&c);

		for(int i=0;i<c;++i)
		{
			scanf("%d%d%d",&from,&to,&bdw);

			B[to][from]=(B[from][to]+=bdw);
		}

		while(1){
			queue<int> q;
			q.push(s);
			int tmp;
			memset(visit+1,false,sizeof(bool)*n);
			visit[s]=true;
			min_flow[s]=MAX_B;

			while(!q.empty())
			{
				tmp=q.front();
				q.pop();

				if(tmp==t)
					break;

				for(int i=1;i<=n;++i)
				{
					if(!visit[i]&&B[tmp][i]&&B[tmp][i]>F[tmp][i])
					{
						q.push(i);
						visit[i]=true;
						pre[i]=tmp;
						min_flow[i]=min(min_flow[tmp],B[tmp][i]-F[tmp][i]);
					}
				}
			}

			if(tmp!=t)
				break;

			for(int cur=t;cur!=s;cur=pre[cur])
			{
				F[pre[cur]][cur] += min_flow[t];
				F[cur][pre[cur]] -= min_flow[t];
			}

			ans += min_flow[t];
		}

		printf("Network %d\n",cases++);
		printf("The bandwidth is %d.\n\n",ans);
	}


	return 0;
}

static void init(int n)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			F[i][j]=B[i][j]=0;

	ans=0;
}

static int min(int a,int b)
{
	return a<b?a:b;
}
