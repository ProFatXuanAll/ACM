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

#define MAX (1000000+1)

static vector<int> set[MAX];
static int root[MAX];
static int sum[MAX];

static void Union(int v1,int v2);
static void Joint(int v1,int v2);

int main(void)
{
	int n, m;
	int op, v1, v2;

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		
		for(int i=1;i<=n;++i)
		{
			set[i].clear();
			set[i].push_back(i);
			root[i]=sum[i]=i;
		}

		for(int i=0;i<m;++i)
		{
			scanf("%d",&op);
			
			switch(op)
			{
				case 1:
					scanf("%d%d",&v1,&v2);
					Union(v1,v2);
					break;
				case 2:
					scanf("%d%d",&v1,&v2);
					Joint(v1,v2);
					break;
				case 3:
					scanf("%d",&v1);
					printf("%ld %d\n",set[root[v1]].size(),sum[root[v1]]);
					break;
			}
		}
	}

	return 0;
}

static void Union(int v1,int v2)
{
	v1=root[v1];
	v2=root[v2];

	if(v1!=v2)
	{
		if(set[v1].size()>set[v2].size())
		{
			for(int i=0;i<set[v2].size();++i)
			{
				set[v1].push_back(set[v2][i]);
				root[set[v2][i]]=v1;
				sum[v1]+=set[v2][i];
			}
			set[v2].clear();
		}
		else
		{
			for(int i=0;i<set[v1].size();++i)
			{
				set[v2].push_back(set[v1][i]);
				root[set[v1][i]]=v2;
				sum[v2]+=set[v1][i];
			}
			set[v1].clear();
		}
	}
}

static void Joint(int v1,int v2)
{
	if(root[v1]!=root[v2])
	{
		auto iter=set[root[v1]].begin();
		while(*iter!=v1)
		{
			++iter;
		}
		
		set[root[v2]].push_back(v1);
		sum[root[v2]]+=v1;
		sum[root[v1]]-=v1;
		set[root[v1]].erase(iter);
		root[v1]=root[v2];
	}
}
