#include<stdio.h>

typedef unsigned long long int ulld;

ulld st[1 << 21];
int pivot = 1 << 20;
int n, m, k;
int mod = 1000000007;

ulld query(int node, int from, int to, int left, int right) {
	if (from > right || to < left) return 1;
	else if (from <= left && right <= to) return  st[node];
	ulld q1 = query(node * 2, from, to, left, (left + right) / 2);
	ulld q2 = query(node * 2 + 1, from, to, (left + right) / 2 + 1, right);
	return ((q1 != -1 ? q1 : 1 )* (q2 != -1 ? q2 : 1)) % mod;
}

void update(int val, int idx) {
	st[idx] = val;
	idx >>= 1;
	while (idx) {
		st[idx] = ((st[idx * 2]!=-1 ? st[idx * 2] : 1) * (st[idx * 2 + 1] != -1 ? st[idx * 2 + 1] : 1)) % mod;
		idx >>= 1;
	}
}

int main() {
	int x, y, z;
	for (int i = 0; i < 1 << 21; i++) st[i] = -1;
	for (scanf("%d%d%d", &n, &m, &k), y = 0; y < n; y++) {
		scanf("%d", &x);
		update(x, pivot + y);
	}
	for (int i = 0; i < m + k; i++) {
		scanf("%d%d%d", &x, &y, &z);
		if (x & 1) update(z, y + pivot-1);
		else printf("%lld\n", query(1, y, z, 1, pivot));
	}
}