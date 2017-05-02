#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;
#define MAX (25+1)

bool G[MAX][MAX], GT[MAX][MAX];

static void init(int n);
static bool visit[MAX];
static int f[MAX], t;
static void DFS(int v,const int& sz);
static void DFS2(int v,const int& sz,int stack[],int& top);

int main(void)
{
	int n, m, set=1;
	string name1, name2;
	int tmp_stack[MAX], tmp_top;

	while(1)
	{
		cin >> n >> m;

		if(n==0&m==0)
		{
			break;
		}
	
		init(n);
		map<string,int> hash;
		map<int, string> rehash;
		int hf=1;

		for(int i=0;i<m;i++)
		{
			int from, to;
			cin >> name1 >> name2;

			if(!hash[name1])
			{
				hash[name1]=hf;
				rehash[hf]=name1;
				from=hf;
				hf++;
			}
			else
			{
				from=hash[name1];
			}

			if(!hash[name2])
			{
				hash[name2]=hf;
				rehash[hf]=name2;
				to=hf;
				hf++;
			}
			else
			{
				to=hash[name2];
			}

			G[from][to]=true;
			GT[to][from]=true;
		}

		for(int i=1;i<=n;i++)
		{
			if(!visit[i])
			{
				visit[i]=true;
				DFS(i,n);
				f[t++]=i;
			}
		}

		cout << "Calling circles for data set " << set++ << ":" << endl;
		memset(visit+1,false,sizeof(bool)*n);
		for(int i=t-1;i>=1;i--)
		{
			if(!visit[f[i]])
			{
				visit[f[i]]=true;
				tmp_top=0;
				tmp_stack[tmp_top++]=f[i];
				DFS2(f[i],n,tmp_stack,tmp_top);
				bool flag=false;
				for(int j=0;j<tmp_top;j++)
				{
					flag=true;
					if(!j)
						cout << rehash[tmp_stack[j]];
					else
						cout << ", " << rehash[tmp_stack[j]];
				}
				if(flag)
					cout << endl;
			}
		}
		cout << endl;
	}

	return 0;
}

static void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		visit[i]=false;
		for(int j=1;j<=n;j++)
		{
			G[i][j]=false;
			GT[i][j]=false;
		}
	}
	t=1;
}

static void DFS(int v,const int& sz)
{
	for(int i=1;i<=sz;i++)
	{
		if(G[v][i]&&!visit[i])
		{
			visit[i]=true;
			DFS(i,sz);
			f[t++]=i;
		}
	}
}

static void DFS2(int v,const int& sz,int stack[],int& top)
{
	for(int i=1;i<=sz;i++)
	{
		if(GT[v][i]&&!visit[i])
		{
			visit[i]=true;
			stack[top++]=i;
			DFS2(i,sz,stack,top);
		}
	}
}
