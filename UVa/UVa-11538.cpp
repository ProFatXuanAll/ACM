#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

static inline void row(int M, int N, long long int& ans);
static inline void col(int M, int N, long long int& ans);
static void dia(int M, int N, long long int& ans);

int main(void)
{
	int M, N;
	long long int ans;
	while(1){
		scanf("%d%d",&M,&N);
		
		if(M==0&&N==0){
			break;
		}
		if(M<N){
			ans=M;
			M=N;
			N=ans;
		}
		ans=0;

		row(M,N,ans);
		col(M,N,ans);
		dia(M,N,ans);
		printf("%lld\n",ans);
	}


	return 0;
}

static inline void row(int M, int N, long long int& ans)
{
	ans+=(long long int)N*(N-1)*M;
}

static inline void col(int M, int N, long long int& ans)
{
	ans+=(long long int)M*(M-1)*N;
}

static void dia(int M, int N, long long int& ans)
{
	long long int tmp_ans1=0, tmp_ans2=0;
	int i;

	for(i=N-1;i>=2;i--){
		row(1,i,tmp_ans1);
	}
	tmp_ans1*=(long long int)2;
	row(M-N+1,N,tmp_ans2);
	ans+=(tmp_ans1+tmp_ans2)*(long long int)2;
}
