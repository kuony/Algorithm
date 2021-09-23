#include<stdio.h>

const int inf = 1000000001;
int n, m;
int st[1 << 18];
int pivot = 1 << 17;

inline int small(int x,int y) { return x > y ? y : x; }

void update(int idx, int val) {
	st[idx] = val;
	idx >>= 1;
	while (idx) {
		st[idx] = small(st[idx * 2], st[idx * 2+1]);
		idx >>= 1;
	}
}

int query(int node,int left, int right, int from, int to) {
	if (left > to || from > right) return inf;
	if (from <= left && to >= right) return st[node];
	return small(query(node*2,left,(left+right)/2,from,to)
		, query(node * 2 +1, (left + right) / 2 +1, right, from, to));
}

int main() {
	int x, y, z;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		update(pivot + i, x);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		if (x & 1) update(pivot + y - 1, z);
		else printf("%d\n", query(1, 1, pivot, y, z));
	}
}