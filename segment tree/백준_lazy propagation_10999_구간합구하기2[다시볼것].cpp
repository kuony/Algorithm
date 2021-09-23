#include<stdio.h>

typedef long long lld;

lld st[(1 << 21) + 10];
lld lazy[(1 << 21) + 10];
lld pivot = 1 << 20;
lld  n, m, k;

void lp(lld  node, lld from, lld to) {
	if (lazy[node]) {
		st[node] += (to - from + 1) * lazy[node];
		if (from != to) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

lld query(lld node, lld from, lld to, lld left, lld right) {
	lp(node, left, right);
	if (from > right || to < left) return 0;
	if (left >= from && to >= right) return st[node];
	lld tmp = query(node * 2, from, to, left, (left + right) / 2) +
		query(node * 2 + 1, from, to, (left + right) / 2 + 1, right);
	return tmp;
}

void update(lld value, lld idx) {
	st[idx] = value;
	idx >>= 1;
	while (idx) {
		st[idx] = st[idx * 2] + st[idx * 2 + 1];
		idx >>= 1;
	}
}

void prop(lld val, lld node, lld from, lld to, lld left, lld right) {
	lp(node, left, right);
	if (from > right || to < left) return;
	else if (left >= from && to >= right) {
		st[node] += (right - left + 1) * val;
		if (left != right) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	prop(val, node * 2, from, to, left, (left + right) / 2);
	prop(val, node * 2 + 1, from, to, (left + right) / 2 + 1, right);
	st[node] = st[node * 2] + st[node * 2 + 1];
}

int main() {
	lld i, x, y, z;
	for (scanf("%lld%lld%lld", &n, &m, &k), i = 0; i < n; i++) {
		scanf("%lld", &x);
		update(x, i + pivot);
	}
	for (lld i = 0; i < k + m; i++) {
		lld flag;
		scanf("%lld", &flag);
		if (flag & 1) {
			scanf("%lld%lld%lld", &x, &y, &z);
			prop(z, 1, x, y, 1, pivot);
		}
		else {
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", query(1, x, y, 1, pivot));
		}
	}

}