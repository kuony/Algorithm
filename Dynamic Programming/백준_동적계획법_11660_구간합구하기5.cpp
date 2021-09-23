#include<cstdio>

using namespace std;

typedef long long int lld;
int n, m;
lld cp[1 << 10 +1][1 << 10 +1];
lld ls[1 << 10 + 1][1 << 10 + 1];
lld rs[1 << 10 + 1][1 << 10 + 1];
lld sum[1<<10+1];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= n; j++) { scanf("%d", &cp[i][j]); sum[i] += cp[i][j]; }
	}
	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) scanf("%d", &cp[i][j]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) scanf("%d", &cp[i][j]);
	}
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		//printf("%lld\n",mx);
	}
}