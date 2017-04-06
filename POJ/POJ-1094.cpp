#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_CHAR (26)
#define MAX_INPUT (1000)
#define MAX_STRING_LEN (4)

using namespace std;

static int n, m;
static char map[MAX_CHAR][MAX_CHAR];
static char input[MAX_INPUT][MAX_STRING_LEN];
static int in[MAX_CHAR];
static int in2[MAX_CHAR];
static int node[MAX_CHAR];
static char output[MAX_CHAR];
static int top;

static bool notbelong(char a,char b);
static int TopologicalSort(void);

int main(void)
{
	bool find;
	bool wrong;
	int ans;
	int record;

	while(1){
		scanf("%d%d",&n,&m);
		
		if(n==0&&m==0){
			break;
		}
		
		memset(node,0,sizeof(node));
		memset(in,0,sizeof(in));
		find=false;
		wrong=false;
		for(int i=0;i<m;i++){
			scanf("%s",input[i]);	/* get input */
			
			if(!find&&!wrong){
				if(notbelong(input[i][0],input[i][2])){
					map[input[i][0]-'A'][node[input[i][0]-'A']++]=input[i][2];
					in[input[i][2]-'A']++;
					memcpy(in2,in,sizeof(in));

					if((ans=TopologicalSort())==n){
						record=i+1;
						find=true;
						printf("Sorted sequence determined after %d relations: ",record);
						for(int j=0;j<n;j++){
							printf("%c",output[j]);
						}
						puts(".");
					}
					else if(ans==-1){
						printf("Inconsistency found after %d relations.\n",i+1);
						wrong=true;
					}
				}
			}
		}

		if(!find&&!wrong){
			printf("Sorted sequence cannot be determined.\n");
		}
	}

	return 0;
}

static bool notbelong(char a,char b){
	if(a==b){
		return false;
	}
	for(int i=0;i<node[a-'A'];i++){
		if(map[a-'A'][i]==b){
			return false;
		}
	}
	return true;
}
static int TopologicalSort(void)
{
	int travel=0;
	int queue[MAX_CHAR];
	int front=0, rear=0;
	bool loop=false;
	bool ND=false;

	for(int i=0;i<n;i++){
		if(in2[i]==0&&node[i]!=0){
			queue[rear++]=i;
		}
	}
	if(rear==0){	/* error */
		return -1;
	}
	else if(rear!=1){	/* can't determind */
		ND=true;
	}

	while(front!=rear){
		for(int j=0;j<node[queue[front]];j++){
			in2[map[queue[front]][j]-'A']--;
			if(in2[map[queue[front]][j]-'A'] == 0){
				queue[rear++]=map[queue[front]][j]-'A';
				continue;
			}
			else if(in2[map[queue[front]][j]-'A'] < 0){
				return -1;
			}
		}
		output[travel++]=queue[front++]+'A';
		if(rear-front>1){
			ND=true;
		}
	}

	for(int j=0;j<n;j++){
		if(in2[j]!=0){
			return -1;
		}
	}

	return ND?0:travel;
}
