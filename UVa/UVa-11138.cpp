#include <stdio.h>

#define MAX_BOLTS (500)
#define MAX_NUTS (500)

/*~global~copy~of~the~input~data~*/
int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS];

void read_input_data(void)
{
	int n,b;
	
	scanf("%d%d",&bolts,&nuts);

	for(b=0;b<bolts;b++)
	{
		for(n=0;n<nuts;n++)
		{
			scanf("%d",&fits[b][n]);
		}
	}
}

/* data used to match nuts with bolts */
int nut_used[MAX_NUTS];
int bestmatched;
int llink[MAX_BOLTS], rlink[MAX_NUTS];

void init_match(void)
{
	int b,n;
	
	bestmatched=0;
	
	for(b=0;b<bolts;++b)
		llink[b]=-1;

	for(n=0;n<nuts;++n)
		rlink[n]=-1;
}

int match_bolt(int boltno)
{
	int n;

	for(n=0;n<nuts;n++)
	{
		if(!fits[boltno][n]||nut_used[n])
			continue;

		nut_used[n]=1;

		if(rlink[n]==-1||match_bolt(rlink[n]))
		{
			llink[boltno]=n;
			rlink[n]=boltno;
			return 1;
		}
	}

	return 0;
}

int main(){
	int cases,caseno;
	int b, n;

	scanf("%d",&cases);
	
	for(caseno=1;caseno<=cases;caseno++)
	{
		read_input_data();
		init_match();

		for(b=0;b<bolts;++b)
		{
			for(n=0;n<nuts;++n)
				nut_used[n]=0;

			if(match_bolt(b))
				++bestmatched;
		}

		printf("Case %d: ",caseno);
		printf("a maximum of %d nuts and bolts ",bestmatched);
		printf("can be fitted together\n");
	}
	
	return 0;
}
