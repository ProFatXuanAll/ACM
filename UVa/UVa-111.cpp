#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAX (20+1)

static int correct[MAX];
static int input[MAX];
static int LCS[MAX][MAX];

int main(void)
{
	int n, tmp;

	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		correct[tmp-1]=i;
	}
	
	for(int i=0;i<=n;i++){
		LCS[i][0]=0;
		LCS[0][i]=0;
	}

	while(scanf("%d",&tmp)!=EOF){
		input[tmp-1]=0;
		for(int i=1;i<n;i++){
			scanf("%d",&tmp);
			input[tmp-1]=i;
		}

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(input[i-1]==correct[j-1]){
					LCS[i][j]=LCS[i-1][j-1]+1;
				}
				else if(LCS[i-1][j]>LCS[i][j-1]){
					LCS[i][j]=LCS[i-1][j];
				}
				else{
					LCS[i][j]=LCS[i][j-1];
				}
			}
		}

		printf("%d\n",LCS[n][n]);
	}

	return 0;
}
