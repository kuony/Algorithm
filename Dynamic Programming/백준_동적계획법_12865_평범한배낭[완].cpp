#include<iostream>
#include<vector>
using namespace std;

typedef pair<int, int> pi;
vector<pi> stuff;
int dp[100001];
//pi lw[101],rw[101];
int n, w;
int mx = -1;

pi operator+(pi x,pi y) { return make_pair(x.first + y.first, x.second + y.second); }
int big(int x, int y) { return x > y ? x : y; }

int main() {
	cin >> n >> w;
	int cnt = 0;
	stuff.resize(n);
	for (int i = 0; i < n; i++) cin >> stuff[i].first >> stuff[i].second;
	for (int i = 0; i <= w; i++)
		dp[i] = -1;
	for (int i = 0; i < n; i++) {
		for (int j = w; j >= 0; j--) {
			if (j + stuff[i].first <= w) {
				if (dp[j] != -1) {
					dp[j + stuff[i].first] = big(dp[j + stuff[i].first],
						dp[j] + stuff[i].second);
				}
				else if (j==0){
					dp[j + stuff[i].first] = big(dp[j + stuff[i].first],
						stuff[i].second);
				}
				mx = big(mx, dp[j + stuff[i].first]);
				mx = big(mx, dp[j]);
			}
		}
	}
	if (mx == -1) mx = 0;
	cout << mx;
}
	/* 중복을 해결할 방법이 없다.
	for (int i = 0; i <= w; i++) {
		for (int j = 0; j < n; j++) {
			if (i + stuff[j].first <= w) {
				dp[i + stuff[j].first] = big(dp[i + stuff[j].first]
					, dp[i] + stuff[j].second);
				mx = big(mx, dp[i + stuff[j].first]);
			}
		}
	}
	lw[0] = stuff[0];
	rw[n - 1] = stuff[n - 1];
	for (int i = 1; i < n; i++) lw[i] = stuff[i] + lw[i - 1];
	for (int i = n-1; i >=0; i--) rw[i] = stuff[i] + rw[i + 1];
	*/