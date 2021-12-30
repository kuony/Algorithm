/*
https://www.acmicpc.net/problem/1520

������ ��

������ �ִ�. ��ȭ�¿� �̿��� �������� �̵��� �����ϴ�.
���� ���� ������ ���� ������ �Ʒ��� �̵��ϵ�, ���̰� ��  ���� �������θ�  �̵��ϰ��� �Ѵ�.

�Ƴ�... �ٺ����� �������� ����ȭ �Ѵ�ð� �ڵ� ���ƴٰ� ���� �ι� �����ߴ�..

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