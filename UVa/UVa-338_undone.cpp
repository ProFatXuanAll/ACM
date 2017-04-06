#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX (10)

static void Mul(char a[],char b[],char res[]);
static void OutputWS(int n);

int main(void)
{
	char a[MAX], b[MAX], res[2*MAX];

	scanf("%s",a);

	while(scanf("%s",b)!=EOF){
		Mul(a,b,res);
		puts("");
		scanf("%s",a);
	}

	return 0;
}

static void Mul(char a[],char b[],char res[])
{
	char output[MAX][2*MAX+1];
	int len1, len2, len3;
	int i, counter=0;
	unsigned long long int tmp_a, tmp_b, tmp_len, max_len;
	tmp_a=atoll(a);
	tmp_b=atoll(b);

	sprintf(res,"%llu",tmp_a*tmp_b);
	len1=strlen(a);
	len2=strlen(b);
	len3=strlen(res);

	for(i=0;i<len2;i++){
		sprintf(output[i],"%llu",tmp_a*(unsigned long long int)(b[len2-1-i]-'0'));
	}


	max_len=(len1>=len2?(len1>=len3?len1:len3):(len2>=len3?len2:len3));
	OutputWS(max_len-len1);
	printf("%s\n",a);
	OutputWS(max_len-len2);
	printf("%s\n",b);
	
	for(i=0;i<len2;i++){
		if(output[i][0]=='0'){
			counter++;
		}
	}
	
	tmp_len=len1>len2?len1:len2;
	OutputWS(max_len-tmp_len);
	for(i=0;i<tmp_len;i++){
		printf("-");
	}
	printf("\n");

	if(tmp_a==0||tmp_b==0){
		OutputWS(max_len-1);
		printf("0\n");
		return;
	}
	else if(strcmp(res,output[0])==0){
		printf("%s\n",res);
		return;
	}
	else if(len2-counter<=1){
		OutputWS(max_len-len3);
		printf("%s\n",res);
		return;
	}

	
	for(i=0;i<len2;i++){
		if(output[i][0]=='0'){
			continue;
		}
		OutputWS(max_len-strlen(output[i])-i);
		printf("%s\n",output[i]);
	}
	for(i=0;i<max_len;i++){
		printf("-");
	}
	printf("\n%s\n",res);
}

static void OutputWS(int n)
{
	int i;
	for(i=0;i<n;i++){
		printf(" ");
	}
}
