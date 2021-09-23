#include<stdio.h>

int st[1 << 18];
int pivot = 1 << 17;
int n, m;

int norm(int x) {
	if (x > 0) return 1;
	else if (x < 0) return -1;
	else return 0;
}
void init() {
	for (int i = 0; i < 1 << 18; i++) st[i] = 1;
}

void update(int node, int left, int right, int idx, int val) {
	if (idx<left || idx>right) return;
	if (left == right) {
		st[node] = val;
		return;
	}
	update(node * 2, left, (left + right) / 2, idx, val);
	update(node * 2 + 1, (left + right) / 2 + 1, right, idx, val);
	st[node] = st[node * 2] * st[node * 2 + 1];
}

int query(int node, int left, int right, int from, int to) {
	if (to<left || from>right) return 1;
	if (from <= left && to >= right) return st[node];
	return query(node * 2, left, (left + right) / 2, from, to) *
		query(node * 2 + 1, (left + right) / 2 + 1, right, from, to);
}

int main() {
	int x;
	while (scanf("%d%d", &n, &m) != EOF) {
		init();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			update(1, 1, pivot, i, norm(x));
		}
		for (int i = 0; i < m; i++) {
			char command;
			int from, to;
			scanf(" %c%d%d", &command, &from, &to);
			if (command == 'C') update(1, 1, pivot, from, norm(to));
			else {
				int tmp = query(1, 1, pivot, from, to);
				if (tmp > 0) printf("+");
				else if (tmp < 0) printf("-");
				else printf("0");
			}
		}
		printf("\n");
	}
}