#include<stdio.h>

int seq[1<<21];
int pivot = 1 << 20;

void init() {
	for (int i = 0; i < 1 << 21; i++) seq[i] = 10000001;
}

int big(int x, int y){ return x > y ? x : y;}

void update(int val,int node,int from, int to) {
	if (from == to) {
		seq[node] = seq[node] > val ? val : seq[node];
		return;
	}
	if (val > seq[node * 2])
		update(val, node * 2 + 1, (from + to) / 2 + 1, to);
	else
		update(val, node * 2, from, (from + to) / 2);
	seq[node] = big(seq[node * 2], seq[node * 2 + 1]);
}

int main() {
	int n;
	init();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		update(temp,1,0,pivot-1);
	}
	for (; seq[pivot] != 10000001; pivot++);
	printf("%d", pivot - (1 << 20));
}