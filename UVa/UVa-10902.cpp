#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX (100000)

struct Point
{
	double x;
	double y;
};

struct Line
{
	Point s;
	Point e;
};

double dot(Point& o, Point& a, Point& b)
{
	return (a.x-o.x) * (b.x-o.x) + (a.y-o.y) * (b.y-o.y);
}

double cross(Point& o, Point& a, Point& b)
{
	return (a.x-o.x) * (b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}

bool point_intersect(Point p, Point p1, Point p2)
{
	return cross(p, p1, p2) == 0 && dot(p, p1, p2) <= 0;
}

bool line_intersect(Point& a1, Point& a2, Point& b1, Point& b2)
{
	double c1 = cross(a1, a2, b1);
	double c2 = cross(a1, a2, b2);
	double c3 = cross(b1, b2, a1);
	double c4 = cross(b1, b2, a2);

	if(c1 * c2 < 0 && c3 * c4 < 0)
		return true;
	/*if(c1 == 0 && point_intersect(b1, a1, a2))
		return true;
	if(c2 == 0 && point_intersect(b2, a1, a2))
		return true;
	if(c3 == 0 && point_intersect(a1, b1, b2))
		return true;
	if(c4 == 0 && point_intersect(a2, b1, b2))
		return true;
	*/
	return false;
}

static Line stick[MAX];

int main(void)
{
	int n;
	bool flag;

	while(1)
	{
		scanf("%d",&n);

		if(!n)
			break;
		
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf%lf%lf",&stick[i].s.x,&stick[i].s.y,&stick[i].e.x,&stick[i].e.y);
		}

		printf("Top sticks: ");

		for(int i=0;i<n-1;++i)
		{
			flag=true;
			for(int j=i+1;j<=n-1;++j)
			{
				if(line_intersect(stick[i].s,stick[i].e,stick[j].s,stick[j].e))
				{
					flag=false;
					break;
				}
			}
			if(flag)
				printf("%d, ",i+1);
		}

		printf("%d.\n",n);
	}

	return 0;
}
