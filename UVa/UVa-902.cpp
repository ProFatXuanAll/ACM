#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <iostream>

using namespace std;

#define MAX (550000)
#define MAX_LEN (100000)
#define MAX_N (10+1)

int main(void)
{
	int N, i, len, tmp, max;
	string target;	
	string cur_max;

	while(scanf("%d",&N)!=EOF){
		cin >> target;
		map<string,int>res;
		max=0;
		for(i=0;i+N<=target.size();i++){
			string match = target.substr(i,N);
			if(!res[match]){
				res[match]=1;
			}
			else{
				res[match]++;
			}
			if(res[match]>max){
				max=res[match];
				cur_max = match;
			}
		}
		cout << cur_max << endl;
	}

	return 0;
}
