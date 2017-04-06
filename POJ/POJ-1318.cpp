#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Dictionary{
	public:
		char origin[101];
		char word[101];
		bool operator< ( const Dictionary r ) const {
			return strcmp(origin,r.origin)==-1;
		}
};

int main()
{
	int counter=0;
	Dictionary dictionary[1000];
	char temp[101];

	do{
		fgets(dictionary[counter].origin,101,stdin);
		strcpy(dictionary[counter].word,dictionary[counter].origin);
		sort(dictionary[counter].word,dictionary[counter].word+strlen(dictionary[counter].word)-1);
	}while(strcmp(dictionary[counter++].word,"XXXXXX\n"));
	
	counter--;
	sort(dictionary,dictionary+counter);
	fgets(temp,101,stdin);
	
	while(strcmp(temp,"XXXXXX\n")){
		
		sort(temp,temp+strlen(temp)-1);
		
		int trigger=1;
		
		for(int i=0;i<counter;i++){
			if(strcmp(temp,dictionary[i].word)==0){
				printf("%s",dictionary[i].origin);
				trigger=0;
			}
		}
		
		if(trigger)
			printf("NOT A VALID WORD\n******\n");
		else
			printf("******\n");
		
		fgets(temp,101,stdin);
	}
	
	
	return 0;
}
