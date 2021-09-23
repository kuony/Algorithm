#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
vector<pair<int, int>> vec;
int dp[20000001];
int mx = 100000000;
int mmx = -1;

int main() {
	scanf("%d%d", &n, &m);
	vec.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &vec[i].first);
	for (int i = 0; i < n; i++) scanf("%d", &vec[i].second);
	sort(vec.begin(), vec.end());
	for (int i = 1; i <= 20000000; i++) dp[i] = 1000000;
	for(int i=0;i<n;i++){
		for (int j = m; j >= 0; j--){
				dp[j + vec[i].first] = (dp[j] + vec[i].second) > dp[j + vec[i].first] ?
					dp[j + vec[i].first] : (dp[j] + vec[i].second);
		}
	}
	for (int i = m; i <= 20000000; i++)
		mx = mx > dp[i] ? dp[i] : mx;
	printf("%d", mx);
}