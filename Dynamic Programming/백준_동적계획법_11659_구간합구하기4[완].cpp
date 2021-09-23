#include<iostream>
#include<cstdio>
using namespace std;

typedef long long int lld;

lld ls[100002];
lld rs[100002];
lld cp[100002];
lld n, m,i;
lld sum=0;

int main() {
	scanf("%d%d", &n, &m);
	for (i = 1; i <=n; i++) { scanf("%d",&cp[i]); sum += cp[i]; }
	rs[n] = cp[n], ls[1] = cp[1];
	for (i = 2; i <= n; i++) ls[i] = cp[i] + ls[i-1];
	for (i = n - 1; i >= 1; i--) rs[i] = cp[i] + rs[i + 1];
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		cout <<sum-(ls[x-1]+rs[y+1])<<"\n";
	}
}