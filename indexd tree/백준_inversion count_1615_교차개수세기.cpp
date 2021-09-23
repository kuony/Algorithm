#include<stdio.h>

typedef long long lld;
lld st[1 << 12], ans;
bool edge[2001][2001];
int n, m, pivot = 1 << 11;

void update(int idx, int val) {
	st[idx] += val;
	idx >>= 1;
	while (idx) {
		st[idx] = st[idx * 2] + st[idx * 2 + 1];
		idx >>= 1;
	}
}

lld query(int node,int left,int right,int from,int to) {
	if (left > to || right < from) return 0;
	if (from <= left && to >= right) return st[node];
	return query(node * 2, left, (left + right) / 2, from, to) +
		query(node * 2 + 1, (left + right) / 2 +1, right, from, to);
}

int main() {
	int x, y;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		edge[x][y] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (edge[i][j]) {
				update(pivot + j - 1, 1);
				ans += query(1, 1, pivot, j+1, n);
			}
		}
	}
	printf("%lld", ans);
}
