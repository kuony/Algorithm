#include<stdio.h>

int st[1 << 19];
int pivot = 1<<18;
int bias = 1 << 17;
int map[100001];

void init() { 
	for (int i = 0; i < (1 << 19); i++) st[i] = 0; 
	for (int i = 0; i < 100001; i++) map[i] = 0;
}

void update(int idx, int val) {
	st[idx] = val;
	idx >>= 1;
	while (idx) {
		st[idx] = st[idx * 2] + st[idx * 2 + 1];
		idx >>= 1;
	}
}

int query(int node,int left,int right,int from,int to) {
	if (from > right || to < left) return 0;
	if (from <= left && to >= right) return st[node];
	return query(node * 2, left, (left + right) / 2,from, to)+
		query(node * 2 +1, (left + right) / 2 +1,right, from, to);
}

int main() {
	int x,n,m,p;
	//freopen("C.in", "r", stdin);
	//freopen("C.o", "w", stdout);
	scanf("%d", &x);
	while (x--) {
		int bias = 1<<17;
		init();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <=n;i++) {
			update(pivot + i + bias, 1);
			map[i] = bias+i;
		}
		while (m--) {
			scanf("%d", &p);
			printf("%d ", query(1, 1,1<<18, 1, map[p]));
			update(map[p] + pivot, 0);
			update(bias + pivot, 1);
			map[p] = bias--;
		}
		printf("\n");
	}
}