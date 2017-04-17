#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>

using namespace std;

#define MAX_E (5)
#define MAX_F (100)
#define MAX_T (INT_MAX/2)

static void BellmanFord(map<int,map<int,int>>& G,map<int,int>&res);

int main(void)
{
	int n, k;
	int e[MAX_E], f[MAX_F];
	int c, tmp, count;

	while(scanf("%d %d",&n,&k)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&e[i]);
		}
		
		map<int,map<int,int>> G;
		map<int,int> res;

		for(int i=0;i<n;i++){
			count=tmp=0;
			while(isspace(c=getchar()));

			do{
				if(c==' '){
					f[count++]=tmp;
					if(!res[tmp]){
						res[tmp]=MAX_T;
					}
					tmp=0;
				}
				else{
					tmp*=10;
					tmp+=(c-'0');
				}
			}while((c=getchar())!='\n');
			f[count++]=tmp;
			if(!res[tmp]){
				res[tmp]=MAX_T;
			}

			for(int j=0;j<count;j++){
				for(int l=0;l<count;l++){
					if(j!=l){
						if(!G[f[j]][f[l]]){
							if(f[i]>f[l]){
								G[f[j]][f[l]]=e[i]*(f[i]-f[l]);
							}
							else{
								G[f[j]][f[l]]=e[i]*(f[l]-f[i]);
							}
						}
						else{
							if(f[i]>f[l]){
								if(G[f[j]][f[l]]>e[i]*(f[i]-f[l])){
									G[f[j]][f[l]]=e[i]*(f[i]-f[l]);
								}
							}
							else{
								if(G[f[j]][f[l]]>e[i]*(f[l]-f[i])){
									G[f[j]][f[l]]=e[i]*(f[l]-f[i]);
								}
							}
						}
					}
				}
			}
		}

		res[0]=0;

		BellmanFord(G,res);

		for(auto& it: res){
			printf("%d~%d\n",it.first,it.second);
		}

		if(!res[k]){
			printf("IMPOSSIBLE\n");
		}
		else{
			printf("%d\n",res[k]);
		}
	}

	return 0;
}

static void BellmanFord(map<int,map<int,int>>& G,map<int,int>&res)
{
	map<int,int> elev;
	for(auto& it1: G){
		for(auto& it2: G){
			for(auto& it3: it2.second){
				if(res[it2.first]!=MAX_T){
					if((!elev[it3.first]||elev[it3.first]==G[it2.first][it3.first])){
						if(G[it2.first][it3.first]+res[it2.first]<res[it3.first]){
							res[it3.first]=G[it2.first][it3.first]+res[it2.first];
							printf("update %d~>%d: %d\n",it2.first,it3.first,res[it3.first]);
							elev[it3.first]=G[it2.first][it3.first];
						}
					}
					else if(G[it2.first][it3.first]+res[it2.first]+60<res[it3.first]){
						res[it3.first]=G[it2.first][it3.first]+res[it2.first]+60;
						elev[it3.first]=G[it2.first][it3.first];
						printf("update %d~>%d: %d\n",it2.first,it3.first,res[it3.first]);
					}
				}
			}
		}
	}

}
