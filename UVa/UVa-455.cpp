#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX (80+1)

static int find_period(char* target, char* match);

int main(void)
{
	int N, i, len_m, len_t;
	char target[MAX];
	char match[MAX];

	scanf("%d",&N);

	for(i=0;i<N;i++){
		scanf("%s",target);
		
		if(i){
			puts("");
		}
		
		len_t=strlen(target);
		for(len_m=1;len_m<len_t;len_m++){
			if(len_t%len_m!=0){
				continue;
			}
			strncpy(match,target,len_m);
			match[len_m]='\0';
			if(find_period(target,match)){
				break;
			}
		}
		printf("%d\n",len_m);
	}


	return 0;
}

static int find_period(char* target, char* match){
	int value, i, len_t=strlen(target), len_m=strlen(match);
	int check = len_t/len_m;

	for(i=len_m;i+len_m<=len_t;i+=len_m){
		value=0;
		while(value<len_m&&target[i+value]==match[value]){
			value++;
		}
		if(value!=len_m){
			return 0;
		}
	}

	return 1;
}
