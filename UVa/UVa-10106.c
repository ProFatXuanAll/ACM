#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 502

static int a[MAX/2];
static int b[MAX/2];
static int c[MAX];

static int ad,bd,cd,ao,bo;
static void Mul(void);
static void Print(void);

int main(void)
{
	char in;

	do{
		ad=bd=cd=ao=bo=0;
		if(scanf("%c",&in)==EOF){
			return 0;
		}
		else{
			do{
				if(!isspace(in)){
					a[ad]=in-'0';
					ao|=a[ad];
					ad++;
					scanf("%c",&in);
				}
				else{
					break;
				}
			}while(1);
			scanf("%c",&in);
			do{
				if(!isspace(in)){
					b[bd]=in-'0';
					bo|=b[bd];
					bd++;
					scanf("%c",&in);
				}
				else{
					break;
				}
			}while(1);
			memset(c,0,sizeof(c));
			if(ao==0 || bo==0){
				printf("0\n");
			}
			else{
				Mul();
				Print();
			}
		}
	}while(1);
	

	return 0;
}

static void Mul(void)
{
	int i,j,k=0,kp=0;
	for(i=ad-1;i>=0;i--){
		k=kp;
		for(j=bd-1;j>=0;j--){
			c[k]+=a[i]*b[j];
			c[k+1]+=c[k]/10;
			c[k]%=10;
			k++;
		}
		kp++;
	}
	cd=k;
}

static void Print(void)
{
	int i=(c[cd]==0?cd-1:cd);
	for(;i>=0;i--){
		printf("%d",c[i]);
	}
	printf("\n");
}
