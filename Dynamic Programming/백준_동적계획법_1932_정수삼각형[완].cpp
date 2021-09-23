#include<iostream>

using namespace std;

int tri[500][501];
int dp[500][501];
int n;
int ma = -1;

const static int big(int x, int y) { return x > y ? x : y; }

int ddp(int x,int y) {
	if (x == 0 && y == 0) return tri[0][0];
	else if (x < 0 || y<0)return -1;
	else if (dp[x][y]) return dp[x][y];
	dp[x][y] = big(ddp(x-1,y),ddp(x-1,y-1)) +tri[x][y];
	return dp[x][y];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> tri[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int  tmp = ddp(n - 1, i);
		ma = big(ma,tmp);
	}
	cout << ma;
}