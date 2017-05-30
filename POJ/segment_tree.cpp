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

#define MAX (1000000)

int s[MAX];

struct Node
{
	int valmax, valmin;
	Node *l, *r;

	void update(int v)
	{
		valmin=v;
		valmax=v;
	}

	void pull()
	{
		valmax=max(l->valmax,r->valmax);
		valmin=min(l->valmin,r->valmin);
	}
};

Node* build(int L,int R)
{
	// create new node
	Node* now=new Node();

	// (1) is this node a leaf
	if(L==R)
	{
		now->update(s[L]);
		return now;
	}

	int mid=(L+R)>>1;

	// (2) create left subtree
	now->l=build(L,mid);

	// (3) create right subtree
	now->r=build(mid+1,R);

	// (4) pull
	now->pull();

	return now;
}

int querymax(Node* now,int L,int R,int x,int y)
{
	// (1) There is no overlap between [L, R] and [x, y]
	//     => [x y L R] or [L R x y]
	if(x>R || y<L)
		return -INF;

	// (2) [x, y] completely include [L, R]
	//     => [x L R y]

	if(x<=L && y>=R)
		return now->valmax;

	// (3) Others (partial overlap)
	int mid=(L+R)>>1;

	return max( querymax(now->l,L,mid,x,y), querymax(now->r,mid+1,R,x,y));
}

int querymin(Node* now,int L,int R,int x,int y)
{
	// (1) There is no overlap between [L, R] and [x, y]
	//     => [x y L R] or [L R x y]
	if(x>R || y<L)
		return INF;

	// (2) [x, y] completely include [L, R]
	//     => [x L R y]

	if(x<=L && y>=R)
		return now->valmin;

	// (3) Others (partial overlap)
	int mid=(L+R)>>1;

	return min( querymin(now->l,L,mid,x,y), querymin(now->r,mid+1,R,x,y));
}

void modify(Node* now, int L, int R, int x, int v)
{
	// (1) is this node a leaf
	if(L==R)
	{
		now->update(now->valmin+v);
		now->update(now->valmax+v);
	}

	// (2) modify the subtree which contains x
	int mid=(L+R)>>1;

	if(x<=mid)
	{
		modify(now->l, L, mid, x, v);
	}
	else
	{
		modify(mow->r, mid+1, R, x, v);
	}

	// (3) pull
	now->pull();
}

void clean(Node* now, int L, int R)
{
	if(L==R)
	{
		delete now;
		return;
	}

	int mid=(L+R)>>1;

	clean(now->l, L, mid);
	clean(now->r, mid+1, R);
	delete now;
}

int main(void)
{

	return 0;
}
