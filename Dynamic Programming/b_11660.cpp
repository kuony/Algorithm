#include<cstdio>
using namespace std;

int board[1026][1026];

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <=m; i++) {
		int rowsum = 0;
		for (int j = 1; j <=m; j++) {
			int temp;
			scanf("%d", &temp);
			board[i][j] += temp;
			if (i == 1 && j == 1) continue;
			else if (i == 1) board[i][j] += board[i][j - 1];
			else if (j == 1) {
				board[i][j + 1] += board[i][j];
				board[i][j] += board[i - 1][j];
			}
			else {
				board[i][j + 1] += board[i][j];
				board[i][j] += board[i-1][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2, ans=0;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		ans = board[x2][y2];
		if (y1 - 1 >= 1) ans -= board[x2][y1 - 1];
		if (x1 - 1 >= 1) ans -= board[x1-1][y2];
		if (x1 - 1 >= 1 && y1 - 1 >= 1) ans += board[x1-1][y1-1];
		printf("%d\n", ans);
	}
	return 0;
}