#include<stdio.h>

int st[1 << 18];
int lazy[1 << 18];
int pivot = 1 << 17;

void propagation(int node, int left, int right) {
	if (lazy[node]) {
		st[node] = (right - left + 1) - st[node];
		if (left != right) {
			lazy[node * 2] = lazy[node * 2]^1;
			lazy[node * 2+1] = lazy[node * 2 +1]^1;
		}
		lazy[node] = lazy[node] ^ 1;
	}
}

int query(int node, int from, int to, int left, int right) {
	propagation(node, left, right);
	if (from > right || to < left) return 0;
	if (from <= left && to >= right) return st[node];
	return query(node * 2, from, to, left, (left + right) / 2) +
		query(node * 2 +1, from, to, (left + right) / 2 +1, right);
}

void update(int node,int from, int to,int left, int right) {
	propagation(node, left, right);
	if (from > right || to < left) return;
	if (from <= left && to >= right) {
		if (left != right) {
			lazy[node * 2] = lazy[node * 2] ^ 1;
			lazy[node * 2 + 1] = lazy[node * 2 + 1] ^ 1;
		}
		st[node] = (right - left + 1) - st[node];
		return;
	}
	update(node * 2, from, to, left, (left + right) / 2);
	update(node * 2 + 1, from, to, (left + right) / 2 + 1, right);
	st[node] = st[node * 2] + st[node * 2+1];
}

int main() {
	int n, m;
	int x, y, z;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &x, &y, &z);
		if (x & 1) printf("%d\n", query(1, y, z, 1, pivot));
		else update(1, y, z, 1, pivot);
	}
}