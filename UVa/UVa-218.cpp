#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX (100000)

struct Point
{
	double x;
	double y;
	bool operator <(Point in)
	{
		if(x==in.x)
			return y<in.y;
		return x<in.x;
	}
};

static double cross(Point o,Point a,Point b);
static double sq(double a);
static int Andrew_Montone(void);

static int n;
static Point trap[MAX];
static Point chain[MAX];

int main(void)
{
	int count;
	int times=0;
	double len;

	while(1)
	{
		scanf("%d",&n);

		if(!n)
			break;

		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf",&trap[i].x,&trap[i].y);
		}

		sort(trap,trap+n);

		count=Andrew_Montone();

		printf("Region #%d:\n",++times);
		
		len=0;

		for(int i=0;i<count-1;++i)
		{
			printf("(%.1lf,%.1lf)-",chain[i].x,chain[i].y);
			len+=sqrt(sq(chain[i].x-chain[i+1].x)+sq(chain[i].y-chain[i+1].y));
		}
		printf("(%.1lf,%.1lf)\n",chain[count-1].x,chain[count-1].y);
		printf("Perimeter length = %.2f\n\n",len);
	}

	return 0;
}

static double cross(Point o,Point a,Point b)
{
	return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}

static double sq(double a)
{
	return a*a;
}

static int Andrew_Montone(void)
{
	int m=0;

	for(int i=0;i<n;++i)
	{
		while(m>=2 && cross(chain[m-2], chain[m-1], trap[i]) >= 0)
			m--;

		chain[m++] = trap[i];
	}

	for(int i=n-2, t=m+1;i>=0;--i)
	{
		while(m>=t && cross(chain[m-2], chain[m-1], trap[i]) >= 0)
			m--;

		chain[m++] = trap[i];
	}

	//m--;

	return m;
}
