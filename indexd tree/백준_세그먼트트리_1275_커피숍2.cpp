#include<stdio.h>

typedef long long int lld;
lld st[1 << 20];
int pivot = 1 << 19;
int n,q;

void update(int node, int left, int right,int idx, int val) {
	if (idx<left || idx>right) return;
	if (left == right) {
		st[node] = val;
		return;
	}
	update(node * 2, left, (left + right) / 2, idx, val);
	update(node * 2+1, (left + right) / 2+1, right, idx, val);
	st[node] = st[node * 2] + st[node * 2 + 1];
}

lld query(int node, int left, int right, int from, int to) {
	if (to<left || from>right) return 0;
	if (from <=left && right <= to) return st[node];
	return query(node * 2, left, (left + right) / 2, from, to) + query(node * 2 + 1, (left + right) / 2 + 1, right, from, to);
}
int main() {
	int i, x, y, z, t;
	for (scanf("%d%d", &n, &q), i = 1; i <=n; i++) {
		scanf("%d", &x);
		update(1, 1, pivot, i, x);
	}
	while (q--) {
		scanf("%d%d%d%d", &x, &y, &z, &t);
		int pp;
		if (x > y) {
			pp = x;
			x = y;
			y = pp;
		}
		printf("%lld\n", query(1, 1, pivot, x, y));
		update(1, 1, pivot, z, t);
	}
}
