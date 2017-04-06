#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

#define MAX_CHAR (26)
#define MAX_STRING (10000)
#define MAX_STRING_LEN (21)

static char map[MAX_CHAR][MAX_CHAR];
static int num_str=0;
static char str[MAX_STRING][MAX_STRING_LEN];
static int node[MAX_CHAR]={0};
static bool in[MAX_CHAR]={false};
static bool visit[MAX_CHAR]={false};
static char print[MAX_CHAR]={'\0'};
static void DFS(int n);
static int top=0;

int main(void)
{
	while(1){
	memset(visit,0,sizeof(visit));
		while(1){

			if(scanf("%c",&str[num_str][0])==EOF){
				return 0;
			}
			
			if(isspace(str[num_str][0])){
				continue;
			}
	
			if(str[num_str][0]=='#'){
				break;
			}

			scanf("%s",str[num_str++]+1);

		}
	
		for(int i=0;i<num_str-1;i++){
			if(str[i][0]!=str[i+1][0]){
				map[str[i][0]-'A'][0] = str[i+1][0];
				node[str[i][0]-'A']=1;
				in[str[i+1][0]-'A']=true;
			}
		}

		for(int i=0;i<num_str-1;i++){
			for(int j=0, flag=0;str[i][j]!='\0'&&str[i+1][j]!='\0';j++){
				if(str[i][j]==str[i+1][j]){
					continue;
				}
				else if(j==0){
					break;
				}
				else{
					for(int k=0;k<node[str[i][j]-'A'];k++){
						if(map[str[i][j]-'A'][k]==str[i+1][j]){
							flag=1;
							break;
						}
					}
					if(!flag){
						map[str[i][j]-'A'][node[str[i][j]-'A']]=str[i+1][j];
						node[str[i][j]-'A']++;
						in[str[i+1][j]-'A']=true;
					}
					break;
				}
			}
		}

		for(int i=0;i<MAX_CHAR;i++){
			if(node[i]!=0&&in[i]==0){
				visit[i]=true;
				DFS(i);
				break;
			}
		}

		for(int i=top-1;i>=0;i--){
			printf("%c",print[i]);
		}
		puts("");

		top=num_str=0;
		memset(visit,0,sizeof(visit));
		memset(in,0,sizeof(in));
		memset(map,0,sizeof(map));
		memset(node,0,sizeof(node));
		memset(print,0,sizeof(print));
	}
	return 0;
}

static void DFS(int n){
	for(int i=0;i<node[n];i++){
		if(visit[map[n][i]-'A']==false){
			visit[map[n][i]-'A']=true;
			DFS(map[n][i]-'A');
		}
	}

	print[top++]=n+'A';

}
