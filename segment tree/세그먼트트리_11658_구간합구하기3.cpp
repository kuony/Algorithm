#include<stdio.h>

int n, m;
int st[(1<<11)+10][(1<<11)+10];
int pivot = 1 << 10;

void query_d1(int ay, int ax, int val) {
	st[ay][ax] = val;
	ax >>= 1;
	while (ax) {
		st[ay][ax] = st[ay][ax * 2] + st[ay][ax * 2+1];
		ax >>= 1;
	}
}

void query_d2() {

}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {

		}
}