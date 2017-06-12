#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;
};

int dot(Point& o, Point& a, Point& b)
{
	return (a.x-o.x) * (b.x-o.x) + (a.y-o.y) * (b.y-o.y);
}

int cross(Point& o, Point& a, Point& b)
{
	return (a.x-o.x) * (b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}

bool point_intersect(Point p, Point p1, Point p2)
{
	return cross(p, p1, p2) == 0 && dot(p, p1, p2) <= 0;
}

bool line_intersect(Point& a1, Point& a2, Point& b1, Point& b2)
{
	int c1 = cross(a1, a2, b1);
	int c2 = cross(a1, a2, b2);
	int c3 = cross(b1, b2, a1);
	int c4 = cross(b1, b2, a2);

	if(c1 * c2 < 0 && c3 * c4 < 0)
		return true;
	if(c1 == 0 && point_intersect(b1, a1, a2))
		return true;
	if(c2 == 0 && point_intersect(b2, a1, a2))
		return true;
	if(c3 == 0 && point_intersect(a1, b1, b2))
		return true;
	if(c4 == 0 && point_intersect(a2, b1, b2))
		return true;

	return false;
}

bool in(Point& o, Point& a, Point& b)
{
	return a.x<=o.x && o.x<=b.x && a.y<=o.y && o.y<=b.y;
}

int min(int a,int b)
{
	return a<b?a:b;
}

int max(int a,int b)
{
	return a>b?a:b;
}

int main(void)
{
	int n;
	Point ls, le, r1, r2, r3, r4, rmin, rmax;

	scanf("%d",&n);

	for(int i=0;i<n;++i)
	{
		scanf("%d%d%d%d%d%d%d%d",&ls.x,&ls.y,&le.x,&le.y,&r1.x,&r1.y,&r2.x,&r2.y);
		r3.x=r1.x;
		r3.y=r2.y;
		r4.x=r2.x;
		r4.y=r1.y;
		
		rmin.x=min(r1.x,r2.x);
		rmin.y=min(r1.y,r2.y);
		rmax.x=max(r1.x,r2.x);
		rmax.y=max(r1.y,r2.y);

		if(in(ls,rmin,rmax) || in(le,rmin,rmax))
			printf("T\n");
		else if(
			line_intersect(ls,le,r1,r3) ||
			line_intersect(ls,le,r1,r4) ||
			line_intersect(ls,le,r2,r3) ||
			line_intersect(ls,le,r2,r4) 
		)
			printf("T\n");
		else
			printf("F\n");
	}

	return 0;
}
