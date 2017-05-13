#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_N (200+2)

static int G[MAX_N][MAX_N];
static int F[MAX_N][MAX_N];
static bool visit[MAX_N];
static int pre[MAX_N];
static int min_flow[MAX_N];
static int ans;

static void init(int n);
static int min(int a,int b);

int main(void)
{
	int N, M, B, D;
	int from, to, cap;

	while(scanf("%d",&N)!=EOF)
	{
		init(2*N+2);

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&cap);
			G[i][i+N]=cap;
		}

		scanf("%d",&M);

		for(int i=0;i<M;++i)
		{
			scanf("%d%d%d",&from,&to,&cap);
			G[from+N][to]=cap;
		}

		scanf("%d%d",&B,&D);

		vector<int> s;
		vector<int> t;
		for(int i=0;i<B;++i)
		{
			scanf("%d",&to);
			s.push_back(to);
		}

		for(int i=0;i<D;++i)
		{
			scanf("%d",&from);
			t.push_back(from+N);
		}

		while(1){
			
			queue<int> q;
			q.push(0);
			for(int i=0;i<s.size();++i)
				G[0][s[i]]=INT_MAX;
			for(int i=0;i<t.size();++i)
				G[t[i]][2*N+1]=INT_MAX;

			int tmp=0;
			memset(visit,false,sizeof(bool)*(2*N+2));

			visit[0]=true;
			min_flow[0]=INT_MAX;
			min_flow[2*N+1]=0;

			while(!q.empty())
			{
				tmp=q.front();
				q.pop();

				if(tmp==2*N+1)
					break;

				for(int i=0;i<=2*N+1;++i)
				{
					if(!visit[i]&&G[tmp][i]>F[tmp][i])
					{
						q.push(i);
						visit[i]=true;
						pre[i]=tmp;
						min_flow[i]=min(min_flow[tmp],G[tmp][i]-F[tmp][i]);
					}
				}
			}

			if(tmp!=2*N+1)
				break;

			for(int cur=2*N+1;cur!=0;cur=pre[cur])
			{
				F[pre[cur]][cur] += min_flow[2*N+1];
				F[cur][pre[cur]] -= min_flow[2*N+1];
			}

			ans += min_flow[2*N+1];
		}

		printf("%d\n",ans);
	}


	return 0;
}

static void init(int n)
{
	
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			F[i][j]=G[i][j]=0;

	ans=0;
}

static int min(int a,int b)
{
	return a<b?a:b;
}
