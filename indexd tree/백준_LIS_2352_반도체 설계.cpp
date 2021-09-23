#include<stdio.h>

const int inf = 9999999;
int st[1 << 17];
int pivot = 1 << 16;
int n;

void init() { for (int i = 0; i < 1 << 17; i++) st[i] = inf; }
inline int big(int x, int y) { return x > y ? x : y; }

void update(int idx, int val) {
	st[idx] = val;
	idx >>= 1;
	while (idx) {
		st[idx] = big(st[idx * 2],st[idx * 2 + 1]);
		idx >>= 1;
	}
}

int query(int node, int left,int right, int val) {
	if(left == right) return right;
	if (st[node * 2] > val) return query(node * 2, left, (left + right)/2,val);
	return query(node * 2 +1, (left + right) / 2 +1, right, val);
}

int main() {
	int ans , x;
	init();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		update(query(1, 1, pivot, x) + pivot -1, x);
	}
	for (ans = 0; st[ans + pivot] != inf; ans++);
	printf("%d", ans);
}