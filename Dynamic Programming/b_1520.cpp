/*
https://www.acmicpc.net/problem/1520

내리막 길

지도가 있다. 상화좌우 이웃한 곳끼리만 이동이 가능하다.
제일 왼쪽 위에서 제일 오른쪽 아래로 이동하되, 높이가 더  낮은 지점으로만  이동하고자 한다.

아놔... 바보같이 마지막에 최적화 한답시고 코드 고쳤다가 오답 두번 제출했다..

*/

#include<iostream>
#include<vector>

using namespace std;

int n, m;
int direct[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int num[500][500];
int cnt;
vector<vector<int> > map;

void init() {
	for (int i = 0; i < 500 * 500; i++) num[i / 500][i % 500] = -1;
}

int find(int y,int x , int prv) {
	if (x < 0 || y < 0 || x >= m || y >= n) return 0;
	if (prv <= map[y][x]) return 0;
	if (x == m - 1 && y == n - 1) return 1;
	if (num[y][x] != -1) return num[y][x];
	num[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int dy = y + direct[i][0];
		int dx = x + direct[i][1];
		num[y][x] += find(dy, dx, map[y][x]);
	}
	return num[y][x];
}

int main(void) {
	init();
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	map.resize(n);
	for (int i = 0; i < n;i++) {
		map[i].resize(m);
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}
	cout << find(0, 0, 9999999);
}