#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(void){
	int N, total;
	string input;

	scanf("%d",&N);
	getline(cin,input);
	getline(cin,input);

	for(;N>0;N--){
		total=0;
	
		map<string, int>dic;
		while(1){
			if(!getline(cin, input)){
				break;
			}
			if(input==""){
				break;
			}
			dic[input]++;
			total++;
		}
	
		for(map<string,int>::iterator it=dic.begin();it!=dic.end();it++){
			printf("%s %.4f\n",it->first.c_str(),(float)it->second/total*100);
		}

		if(N!=1){
			puts("");
		}
	}
	return 0;
}


/*
#define MAX_LEN (30+1)

struct trie{
	struct trie* sib;
	struct trie* child;
	int count;
	int depth;
	char key;
};

static int total;
static struct trie* head;
static void DFS(struct trie* root);
static void insert(char* match);

int main(void)
{
	int N;
	char input[MAX_LEN];

	scanf("%d ",&N);

	for(;N>0;N--){
		total=0;
		head=malloc(sizeof(struct trie));
		head->count=0;
		head->depth=-1;
		head->key='\0';
		head->sib=NULL;
		head->child=NULL;
		while(1){
			if(fgets(input,MAX_LEN,stdin)==NULL){
				break;
			}
			if(strcmp(input,"\n")==0){
				break;
			}
			input[strlen(input)-1]='\0';
			insert(input);
			total++;
		}
		DFS(head);
		puts("");
	}

	return 0;
}*/
/*
static void DFS(struct trie* root){
	if(root==NULL){
		return;
	}
	else{
		DFS(root->child);
		DFS(root->sib);
	}
	free(root);
}*/
/*
static void insert(char* match){
	struct trie* trav = head;
	struct trie* find = NULL;
	int depth=0;

	while(1){
		if(match[depth]=='\0'){
			trav->count++;
			break;
		}
		if(depth>trav->depth){	// goto child
			if(trav->child){
				trav=trav->child;
			}
			else{
				trav->child=malloc(sizeof(struct trie));
				trav=trav->child;
				trav->depth=depth;
				trav->child=NULL;
				trav->sib=NULL;
				trav->count=0;
				trav->key=match[depth];
			}
		}
		find=trav;
		while(find){
			if(find->key==match[depth]){
				depth++;
				break;
			}
			else if(find->sib){
				find=find->sib;
			}
			else{
				find->sib=malloc(sizeof(struct trie));
				find=find->sib;
				find->depth=depth;
				find->key=match[depth];
				find->count=0;
				find->sib=NULL;
				find->child=NULL;
				trav=find;
				depth++;
			}
		}
	}

}*/
