#include <cstdio>
#include <cstring>
#include <iostream>

#define MAX_LEN (50+1)
#define MAX_INPUT (100+1)
using namespace std;

static int n, m;
static int A, C, G;

static char DNA [MAX_INPUT][MAX_LEN];	// DNA sequence

struct Hash{
	int org;	// original position
	int unst;	// unsortedness
};

struct Hash ht[MAX_INPUT];

static void QSort(int l, int r);

int main(void)
{
	int i, j;
	scanf("%d%d ",&n,&m);
	
	for(i=0;i<m;i++){
		A=C=G=0;
		scanf("%s",DNA[i]);
		ht[i].unst=0;
		ht[i].org=i;
		for(j=n-1;j>=0;j--){
			switch(DNA[i][j]){
				case 'A':
					A++;
					break;
				case 'T':
					ht[i].unst+=A+C+G;
					break;
				case 'C':
					ht[i].unst+=A;
					C++;
					break;
				case 'G':
					ht[i].unst+=A+C;
					G++;
					break;
			}
		}
	}

	QSort(0,m-1);

	for(i=0;i<m-1;i++){
		printf("%s\n",DNA[ht[i].org]);
	}
	printf("%s",DNA[ht[m-1].org]);

	return 0;
}

static void QSort(int l, int r)
{
	int i, j, ref;
	struct Hash tmp;

	if(l<r){
		ref=r;
		for(i=j=l;i<=r-1;i++){
			if(ht[i].unst<ht[ref].unst){
				tmp=ht[i];
				ht[i]=ht[j];
				ht[j]=tmp;
				j++;
			}
		}
		
		tmp=ht[j];
		ht[j]=ht[ref];
		ht[ref]=tmp;
		
		QSort(l,j-1);
		QSort(j+1,r);
	}
}
