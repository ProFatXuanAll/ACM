#include <cstdio>
#include <iostream>

using namespace std;

#define MAX (50000)

struct Data{	// data structure of votes
	int st;	// first vote
	int nd;	// second vote
	int id;	// position id
	void operator - (struct Data & par){	// swap operator
		int tmp;
		tmp=st;
		st=par.st;
		par.st=tmp;
		tmp=nd;
		nd=par.nd;
		par.nd=tmp;
		tmp=id;
		id=par.id;
		par.id=tmp;
	}
	bool operator < (const struct Data & par)const{	// less than operator
		return st<par.st;
	}
};

static struct Data D[MAX];
static int N,K;	// N: number of cows; K: number of cows to second run.

static void QSort(int l,int r);	// quick sort

int main(void)
{
	int i;	// loop counter
	struct Data max;	// max record

	scanf("%d%d",&N,&K);

	for(i=0;i<N;i++){
		scanf("%d%d",&D[i].st,&D[i].nd);
		D[i].id=i+1;
	}

	QSort(0,N-1);	// sort

	max=D[N-K];
	for(i=N-K+1;i<N;i++){
		if(max.nd<D[i].nd){
			max=D[i];
		}
	}
	
	printf("%d\n",max.id);

	return 0;
}

static void QSort(int l, int r)
{
	int i,j;	// loop counter
	int ref;	// reference position

	if(l<r){
		ref=r;
		for(i=j=l;i<=r-1;i++){
			if(D[i]<D[ref]){
				D[i]-D[j];
				j++;
			}
		}
		if(i!=j){
			D[j]-D[ref];
		}
		QSort(l,j-1);
		QSort(j+1,r);
	}
}
