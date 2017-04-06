#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int N;
	
	//freopen("t.txt","w",stdout);
	
	scanf("%d",&N);
	getchar();
	
	for(int i=0;i<N;i++){
		
		stack <char> parenthese;
		bool output = false;
		string symbol;
		
		getline(cin, symbol);
	
		for(int j=0;j<symbol.size();j++){
			switch(symbol.at(j)){
				case '(':
				case '[':
					parenthese.push(symbol.at(j));
					break;
				case ')':
					if(parenthese.empty()||parenthese.top()!='('){
						cout << "No" << endl;
						j+=symbol.size();
						output = true;
					}
					else
						parenthese.pop();
					break;
				case ']':
					if(parenthese.empty()||parenthese.top()!='['){
						cout << "No" << endl;
						j+=symbol.size();
						output = true;
					}
					else
						parenthese.pop();
					break;
			}
		}
		

		if(!output&&parenthese.empty())
			cout << "Yes" << endl;
		else if(!output)
			cout << "No" << endl;
	}
	
	return 0;
}
