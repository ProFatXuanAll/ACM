#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX1 (50000)
#define MAX2 (20)
#define PART_SIZE (10)

static void Div(char dividend[],char divisor[],char quotient[],int& remainder);

int main(void)
{
	char dividend[MAX1];
	char divisor[MAX2];
	char op;
	char quotient[MAX1];
	int remainder;

	while(scanf("%s %c %s",dividend,&op,divisor)!=EOF){
		Div(dividend,divisor,quotient,remainder);
		if(op=='/'){
			printf("%s\n",quotient);
		}
		else{
			printf("%d\n",remainder);
		}
	}

	return 0;
}

static void Div(char dividend[],char divisor[],char quotient[],int& remainder)
{
	int len1, len2;
	int i;
	long long int lli_divisor=atoll(divisor);
	long long int lli_quotient=0, lli_remainder=0;
	int Qptr=0;
	char tmp_part[PART_SIZE+1];
	bool start_flag=false;

	len1=strlen(dividend);
	len2=strlen(divisor);

	if(len1<len2){
		sprintf(quotient,"0");
		remainder=atoi(dividend);
		return;
	}

	for(i=0;i<len1;i++){
		lli_quotient=lli_quotient*10+dividend[i]-'0';

		if(lli_quotient>=lli_divisor){
			sprintf(quotient+Qptr,"%lld",lli_quotient/lli_divisor);
			Qptr=strlen(quotient);
			lli_quotient%=lli_divisor;
			start_flag=true;
		}
		else if(start_flag){
			sprintf(quotient+Qptr,"0");
			Qptr=strlen(quotient);
		}
	}	/* end for */
	
	remainder=lli_quotient;
	
	return;

}
