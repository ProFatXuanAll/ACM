#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define MAX_TIME (240)
#define MAX_EVID (100)
#define MAX_LEN (69)

using namespace std;

struct evidence{
	int score;
	int times;
	char des[MAX_LEN];
	bool operator <(struct evidence& in){
		return times==in.times?score>in.score:times<in.times;
	}
};

struct evidence e[MAX_EVID];

static int pack[MAX_EVID][MAX_TIME+1]={0};
static void ButtomUp(int e_num, int total_time);

int main(void)
{
	int cases;
	int total_time;
	int e_num;
	char tmp[100];


	scanf("%d",&cases);

	for(int i=0;i<cases;i++){
		scanf("%d ",&total_time);
		e_num=0;

		while(1){

			if(fgets(tmp,sizeof(tmp),stdin)==NULL){
				break;
			}
			
			if(strcmp(tmp,"\n")==0){
				break;
			}
			sscanf(tmp,"%d %d %[^\n]",&e[e_num].score,&e[e_num].times,e[e_num].des);
			e_num++;
		}

		sort(e,e+e_num);
		
		ButtomUp(e_num,total_time);
		
		printf("%d\n",pack[e_num-1][total_time]);

	}

	return 0;
}

static void ButtomUp(int e_num, int total_time){
	int v1, v2;

	for(int i=1;i<=total_time;i++){
		for(int j=0;j<e_num;j++){
			v1=0;
			v2=0;
			if((j-1)>=0&&(i-e[j].times)>=0){
				v1=pack[j-1][i-e[j].times]+e[j].score;
			}
			if((j-1)>=0){
				v2=pack[j-1][i];
			}
			pack[j][i]=v1>v2?v1:v2;
		}
	}
}
