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

#define MAX (100)

static void init(int n);
static vector<int> G[100], ans;
static bool visit[MAX];
static int dfn[MAX], low[MAX], child[MAX], t;
static void DFS(int v, int parent);
static int min(int a,int b);

int main(void)
{
	int N, R, cases=1;

	while(1)
	{
		scanf("%d",&N);

		if(!N)
			break;
	
		if(cases!=1)
			puts("");

		string from, to;
		map<string,int>hash;
		map<int,string>invh;
		int top=0;
		init(N);

		for(int i=0;i<N;i++)
		{
			cin >> from;
			hash[from]=top;
			invh[top]=from;
			top++;
		}

		scanf("%d",&R);

		for(int i=0;i<R;i++)
		{
			cin >> from >> to;
			G[hash[from]].push_back(hash[to]);
			G[hash[to]].push_back(hash[from]);
		}

		for(int i=0;i<N;i++)
		{
			if(!visit[i])
			{
				DFS(i,-1);
			}
		}

		cout << "City map #" << cases++ << ": " << ans.size() << " camera(s) found" << endl;
		vector<string> output;
		for(int i=0;i<ans.size();i++)
		{
			output.push_back(invh[ans.at(i)]);
		}
		sort(output.begin(),output.end());
		for(int i=0;i<output.size();i++)
		{
			cout << output.at(i) << endl;
		}

	}

	return 0;
}

static void init(int n)
{
	for(int i=0;i<n;i++)
	{
		G[i].clear();
		visit[i]=false;
		child[i]=0;
	}
	t=0;
	ans.clear();
}

static void DFS(int v, int parent)
{
	bool flag=false;
	visit[v]=true;
	dfn[v]=low[v]=++t;

	for(int i=0;i<G[v].size();i++)
	{
		if(!visit[G[v].at(i)]) /* child */
		{
			++child[v];
			DFS(G[v].at(i),v);
			low[v]=min(low[v],low[G[v].at(i)]);
			if(low[G[v].at(i)]>=dfn[v]) /* articulation point */
			{
				flag=true;
			}
		}
		else if(G[v].at(i)!=parent) /* back edge */
		{
			low[v]=min(low[v],dfn[G[v].at(i)]);
		}
	}

	if(flag && (child[v]>=2 || parent !=-1))
	{
		ans.push_back(v);
	}
}

static int min(int a,int b)
{
	return a<b?a:b;
}
