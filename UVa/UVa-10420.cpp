#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n;
	string country[2005], name;
	
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
	  cin >> country[i];
	  getline(cin, name);
	}
	
	sort(country,country+n);
	
	for(int i=0,count=0,j=0;i<n;i++){
		printf("%s", country[i].c_str());

		for(j=i;j<n;j++){
	  		if(country[i]!=country[j]){
	    		break;
	  		}
	
	  		count++;
		}
	
		printf(" %d\n", count);
		i=j-1;
		count=0;
	}
	
	return 0;
}
