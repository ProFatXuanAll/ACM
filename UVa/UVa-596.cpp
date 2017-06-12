#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX (100000)

struct Point
{
	long long x;
	long long y;
	bool operator <(Point in)
	{
		if(x==in.x)
			return y<in.y;
		return x<in.x;
	}
};

static long long cross(Point o,Point a,Point b);
static int Andrew_Montone(void);
static void output(string name, int count);

static int n;
static Point set[MAX];
static Point chain[MAX];

int main(void)
{
	string str, name;
	const string S="S";
	const string P="P";
	const string END="END";
	char blank;
	int polygon;
	bool flag=false;
	int count;

	while(1)
	{
		cin >> str;
		
		if(str==END)
		{
			output(name,Andrew_Montone());
			break;
		}
		else if(str==S)
		{
			if(flag)
				output(name,Andrew_Montone());

			cin >> name;
			getline(cin,str);
			name+=str;
			n=0;
			flag=true;
		}
		else
		{
			cin >> polygon;
			for(int i=0;i<polygon;++i)
			{
				cin >> set[n+i].x >> set[n+i].y;
			}
			n+=polygon;
		}
	}

	return 0;
}

static long long cross(Point o,Point a,Point b)
{
	return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}

static int Andrew_Montone(void)
{
	int m=0;

	sort(set,set+n);
	
	int j, k;
				
	for(j=1, k=0; j<n; j++)
		if(set[k].x != set[j].x || set[k].y != set[j].y)
			set[++k] = set[j];
		        
	n=k+1;

	for(int i=0;i<n;++i)
	{
		while(m>=2 && cross(chain[m-2], chain[m-1], set[i]) < 0)
			m--;

		chain[m++] = set[i];
	}

	for(int i=n-2, t=m+1;i>=0;--i)
	{
		while(m>=t && cross(chain[m-2], chain[m-1], set[i]) < 0)
			m--;

		chain[m++] = set[i];
	}

	m--;

	return m;
}

static void output(string name, int count)
{
	int start_ptr=0;

	cout << name << " convex hull:" << endl;
	for(int i=1;i<count;++i)
	{
		if(chain[start_ptr].x<chain[i].x || (chain[start_ptr].x==chain[i].x && chain[start_ptr].y>chain[i].y))
			start_ptr=i;
	}

	for(int i=0;i<count;++i)
		printf(" (%lld,%lld)",chain[(i+start_ptr)%count].x,chain[(i+start_ptr)%count].y);
	puts("");
}
