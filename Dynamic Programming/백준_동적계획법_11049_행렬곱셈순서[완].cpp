#include<iostream>
#include<cstdio>

using  namespace std;

int n;
int arr[1001][2];
int ddp[501][501];
int ans = 1;

const static int mi(int x, int y) { return x < y ? x : y;}

int mul(int x, int y,int z) {
	return arr[x][0] * arr[y][0] * arr[z][1];
}

int dp(int from,int to) {
	if (ddp[from][to]) return ddp[from][to];
	else if (to == from) return 0;
	else if (to - from == 1) return mul(from, to, to);
	for (int i = from; i <=to-1; i++) {
		int tmp = dp(from, i) + dp(i+1,to) + mul(from, i+1, to);
		if(ddp[from][to]!=0)
		ddp[from][to] = mi(ddp[from][to],tmp);
		else ddp[from][to] = tmp;
	}
	return ddp[from][to];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <=n; i++) scanf("%d%d", &arr[i][0], &arr[i][1]);
	printf("%d", dp(1,n));
}