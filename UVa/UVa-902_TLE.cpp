#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
//#include <map>

using namespace std;

#define MAX (550000)
#define MAX_LEN (100000)
#define MAX_N (10+1)

struct trie{
	bool valid;
	struct trie* child[26];
	int count;
}t[MAX];

static int top=MAX;
static void init_trie(void);
static int insert_trie(char* match);
static struct trie* lookup_trie(char* match,int& depth);

int main(void)
{
	int N, i, len, tmp, max;
	char target[MAX_LEN];
	char match[MAX_N];
	char cur_max[MAX_LEN];

	while(scanf("%d",&N)!=EOF){
		scanf("%s",target);
		len=strlen(target);

		init_trie();
		max=0;
		for(i=0;i+N<=len;i++){
			strncpy(match,target+i,N);
			match[N]='\0';
			tmp=insert_trie(match);
			if(tmp>max){
				max=tmp;
				strcpy(cur_max,match);
			}
		}
		printf("%s\n",cur_max);
	}
	

	return 0;
}

static void init_trie(void){
	memset(t,0,sizeof(struct trie)*top);
	top=26;
}

static int insert_trie(char* match){
	int depth;
	struct trie* insert;
	insert=lookup_trie(match,depth);
	if(depth==strlen(match)){
		if(insert==NULL){
			return t[match[0]-'a'].count;
		}
		return insert->child[match[depth-1]-'a']->count;
	}
	else{
		if(depth==0){
			insert=&t[match[0]-'a'];
			while(match[depth+1]!='\0'){
				insert->valid=true;
				insert->child[match[++depth]-'a']=&t[top++];
				insert=insert->child[match[depth]-'a'];
			}
			insert->valid=true;
		}
		else{
			while(match[depth]!='\0'){
				insert->child[match[depth]-'a']=&t[top++];
				insert=insert->child[match[depth]-'a'];
				insert->valid=true;
				depth++;
			}
		}
		insert->count++;
		return insert->count;
	}
}

static struct trie* lookup_trie(char* match,int& depth){
	struct trie* trav=&t[match[0]-'a'], *pre=NULL;
	depth=0;
	while(trav&&trav->valid&&match[++depth]!='\0'){
		pre=trav;
		trav=trav->child[match[depth]-'a'];
	}
	if(depth==strlen(match)){
		trav->count++;
	}
	return pre;
}
