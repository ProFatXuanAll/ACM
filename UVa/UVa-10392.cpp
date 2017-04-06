#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <climits>
#define MAX 1000000
using namespace std;

static bool isprime[MAX];
static vector<long long int> prime;
static bool isPrime(long long int);
static void eratosthenes();

int main(void)
{
	long long int in;
	long long int fac;
	eratosthenes();
	
	while(cin>>in){
		if(in==-1){
			break;
		}
		else if(in==1){
			cout << "    " << 1 << endl;
		}
		else if(!isPrime(in)){
			;
		}
		else{
			cout << "    " << in << endl;
			prime.push_back(in);
		}
		cout << endl;
	}
	
	return 0;
}

static void eratosthenes()
{
	int count=0;
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	for(long long int i=2;i<(MAX);i++){
		if(isprime[i]){
			prime.push_back(i);
			for(long long int j=i*i;j<MAX;j+=i){
				isprime[j]=false;
			}
		}
	}
}


static bool isPrime(long long int in)
{
	long long int a = in;
	bool flag = true;
	for(long long int j=0;j<prime.size();j++){
		long long int i=prime.at(j);
		if(i<=sqrt(in)){
			while(a%i==0){
				cout << "    " << i << endl;
				a=a/i;
				flag=false;
			}
			if(a==1){
				break;
			}
		}
		else if(flag==false){
			cout << "    " << a << endl;
			break;
		}
		else{
			break;
		}
	}

	return flag;
}
