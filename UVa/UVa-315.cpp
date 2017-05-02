#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

#define MAX (100+1)

struct graph{
	int to[MAX];
	int count;
};

static struct graph G[MAX];
static bool visit[MAX];
static int dfn[MAX];
static int dfn_count;
static int low[MAX];
static int parent[MAX];
static int child[MAX];
static int ap;
static void init(int N);

static void DFS(int n);
static int min(int a, int b);

int main(void)
{
	int N, head, child;
	string line_convert;
	stringstream ss;

	while(1)
	{
		ss.clear();
		getline(cin,line_convert);
		
		ss << line_convert;
		ss >> N;

		if(N==0)
		{
			break;
		}
	
		init(N);
		ss.clear();

		for(int i=1;i<=N+1;i++)
		{
			getline(cin,line_convert);
			ss << line_convert;
			ss >> head;
			if(head==0)
			{
				ss.clear();
				break;
			}

			while(ss >> child)
			{
				G[head].to[G[head].count]=child;
				G[child].to[G[child].count]=head;
				G[head].count++;
				G[child].count++;
			}
			ss.clear();
		}

		DFS(1);
		cout << ap << endl;
	}

	return 0;
}

static void init(int N)
{
	for(int i=1;i<=N;i++)
	{
		G[i].count=0;
		visit[i]=false;
		child[i]=0;
	}
	dfn_count=1;
	ap=0;
	parent[1]=-1;
}

static void DFS(int n)
{
	bool flag=false;

	dfn[n]=dfn_count;
	low[n]=dfn_count;
	dfn_count++;
	visit[n]=true;

	for(int i=0;i<G[n].count;i++)
	{
		if(!visit[G[n].to[i]]) /* child */
		{
			parent[G[n].to[i]]=n;
			child[n]++;
			DFS(G[n].to[i]);
			low[n]=min(low[G[n].to[i]],low[n]);
			
			if(low[G[n].to[i]]>=dfn[n]) /* at most back to itself */
			{
				flag=true;
			}
		}
		else if(G[n].to[i]==parent[n]) /* parent */
		{
			continue;
		}
		else /* back edge */
		{
			low[n]=min(dfn[G[n].to[i]],low[n]);
		}
	}

	if(flag && (child[n]>=2||parent[n]!=-1)){
		ap++;
	}
}

static int min(int a, int b)
{
	return a>b?b:a;
}
