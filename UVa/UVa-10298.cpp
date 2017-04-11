#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX (1000000+1)

static int find_match(char* target, char* match);

int main(void)
{
	char target[MAX];
	char match[MAX];
	int len_t, len_m, n;

	while(1){
		if(scanf("%[^\n] ",target)==EOF){
			break;
		}

		if(strcmp(target,".")==0){
			break;
		}

		len_t=strlen(target);

		for(len_m=1;len_m<=len_t;len_m++){
			if(len_t%len_m!=0){
				continue;
			}
			strncpy(match,target,len_m);
			match[len_m]='\0';
			if(n=find_match(target,match)){
				break;
			}
		}
		printf("%d\n",n);
	}

	return 0;
}

static int find_match(char* target, char* match){
	int len_t=strlen(target), len_m=strlen(match);
	int count, i, res=0;

	for(i=0;i<len_t;i+=len_m){
		count=0;
		while(count<len_m&&target[i+count]==match[count]){
			count++;
		}
		if(count!=len_m){
			return 0;
		}
		res++;
	}

	return res;
}
