#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 1000005;

int vis[MAXN],prime[MAXN],cnt;
int fac[MAXN],a[MAXN],tot,p[MAXN];
long long s1[MAXN],s2[MAXN];
map<int, int> m;

int lowbit(int x){
	return x&(-x);
}

void update(long long *s, int x, int val){
	while (x <= cnt){
		s[x] += val;
		x += lowbit(x);
	}
}

long long sum(long long *s, int x){
	long long ret = 0;
	while (x > 0){
		ret += s[x];
		x -= lowbit(x);
	}
	return ret;	
}

int solve(int num){
	int n = 0,ret = 0,bit[20];
	while (num){
		bit[n++] = num%10;
		num /= 10;
	}
	for (int i = 0; i < n; i++)
		ret = ret*10+bit[i];
	while (ret < 100000)
		ret *= 10;
	return ret;
}

void init(){
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i < MAXN; i++)
		if (!vis[i]){
			prime[++cnt] = i;
			for (int j = 1; j*i < MAXN; j++)
				vis[i*j] = 1;
		}
	for (int i = 1; i <= cnt; i++)
		a[i] = solve(prime[i]);
	sort(a+1, a+1+cnt);
	for (int i = 1; i <= cnt; i++)
		m[a[i]] = i;
	for (int i = 1; i <= cnt; i++){
		fac[i] = 2;
		int tmp = a[i];
		for (int j = 1; j<=cnt&&prime[j]*prime[j]<=tmp; j++)
			while (tmp%prime[j] == 0){
				tmp /= prime[j];
				fac[i]++;
			}
		if (tmp > 1)
			fac[i]++;
	}
}

int main(){
	char ch[5];
	int k;
	init();
	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
	for (int i = 1; i <= cnt; i++)
		update(s1, i, 1);
	for (int i = 1; i <= cnt; i++)
		update(s2, i, fac[i]);
	while (scanf("%s%d", ch, &k) != EOF){
		if (ch[0] == ‘d‘){
			int pos = m[k/10];
			update(s1, pos, -1);
			update(s2, pos, -fac[pos]);
		}
		else {
			k++;
			int l = 1, r = cnt,mid;
			while (l <= r){
				mid = (l+r)>>1;
				long long tmp = sum(s1, mid);
				if (tmp == k)
					break;
				if (tmp < k)
					l = mid+1;
				else r = mid-1;
			}
			printf("%lld\n", sum(s2, mid));
		}
	}
	return 0;
}
