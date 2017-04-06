#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX (7490+50)
#define CENT (sizeof(cent)/sizeof(int))

using namespace std;

static unsigned long long int way[MAX]={0};
static int cent[] = {1,5,10,25,50};
static void ButtomUp(void);

int main(void)
{
	int input;

	way[0]=1;
	ButtomUp();

	while(scanf("%d",&input)!=EOF){
		printf("%llu\n",way[input]);
	}
	return 0;
}

static void ButtomUp(void){
	for(int i=0;i<CENT;i++){
		for(int j=0;j<MAX;j++){
			way[j+cent[i]]+=way[j];
		}
	}
}
