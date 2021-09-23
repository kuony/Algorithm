#include<iostream>
#include<vector>
using namespace std;

int arr[1001][1001];

int mx(int x, int y) { return x > y ? x : y; }
int mi(int x, int y) { return x < y ? x : y; }

int loop(vector<int>& vec, int from, int to) {
	if (arr[from][to]) return arr[from][to];
	else if (to - from == 1) return arr[from][to] = vec[from] > vec[to] ? vec[from] : vec[to];
	loop(vec, from+1, to);
	loop(vec, from, to-1);
	int lft = vec[from] + mi(arr[from + 2][to], arr[from + 1][to - 1]);
	int rht = vec[to] + mi(arr[from + 1][ to - 1], arr[from][to - 2]);
	arr[from][to] = lft > rht ? lft : rht;
	return arr[from][to];
}

void init() {
	for (int i = 0; i <=1000; i++)
		for (int j = 0; j <=1000; j++) arr[i][j] = 0;
}

int main() {
	int t, n;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> vec(n + 1);
		init();
		for (int i = 1; i <= n; i++) {
			cin >> vec[i];
			arr[i][i] = vec[i];
		}
		if(n == 1) cout << vec[1] << "\n";
		else {
			loop(vec, 1, n);
			cout << arr[1][n] << "\n";
		}
	}
}