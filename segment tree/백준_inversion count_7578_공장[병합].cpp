#include<stdio.h>

typedef long long lld;

//const int inf = -999999999;
int arr[1000001];
int map[500002];
int tmp[500002];
int pivot;
//lld st[1 << 21];
lld ans;
int n;
/*
int min(int x, int y) { return x < y ? y : x; }

int get_pivot(int x) {
	int len = 1;
	for (; len < x; len *= 2);
	return len;
}

int query(int node, int from, int to, int left, int right) {
	if (to <left || from > right)  return inf;
	if (from <= left && right <= to) return st[node];
	if (st[node] > st[to + pivot]) ans += 1;
	int q1 = query(node * 2, from, to, left, (left + right) / 2);
	int q2 = query(node * 2 +1, from, to, (left + right) / 2 +1,right);
	return min(q1, q2);

}

void update(int idx, int val) {
	st[idx] = val;
	idx >>= 1;
	while (idx) {
		st[idx] = min(st[idx * 2],st[idx * 2 + 1]);
		idx >>= 1;
	}
}
*/

void merge(int from,int to) {
	if (from == to) return;
	merge(from, (from + to) / 2);
	merge((from + to) / 2 + 1, to);
	int lp = from;
	int rp = (to+from)/2 +1;
	int cnt = from;
	for (; lp <= (from+to)/2 && rp <= to;) {
		if (map[lp] > map[rp]) {
			tmp[cnt++] = map[rp++];
			ans += ((from + to) / 2 - lp +1);
		}
		else tmp[cnt++] = map[lp++];
	}
	for (; lp <= (to + from) / 2; lp++) tmp[cnt++] = map[lp];
	for (; rp <= to; rp++) tmp[cnt++] = map[rp];
	for (int i = from; i <= to; i++)
		map[i] = tmp[i];
}

int main() {
	int i,x;
	for (scanf("%d", &n), i = 1; i <= n; i++) {
		scanf("%d", &x);
		arr[x] = i;
	}
	//pivot = get_pivot(n);
	//for (int i = 0; i < pivot << 1; i++) st[i] = inf;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		//update(pivot + i - 1, arr[x]);
		map[i] = arr[x];
	}
	merge(1,n);
	printf("%lld", ans);
}