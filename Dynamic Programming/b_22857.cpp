/*
https://www.acmicpc.net/problem/22857

���� �� ¦�� ������ �κ� ����

���̰� n�� ���� s�� �Է¹ް�, ���ϴ� ��ġ���� �ִ� k�� �����Ѵ�.
���� s���� �ִ� k�� ���Ҹ� ������ �������� ¦���� �̷���� �ִ� 
������ �κ� ���� �� ���� �� ���̸� ������.


->  ������ �߸����� ������ ��û���� �ߴ�..
*/


#include<iostream>
#include<vector>

using namespace std;


vector<int> su;
int memo[50001][101];
int n, k;


void init() {
	for (int i = 0; i <= 50000; i++)
		for (int j = 0; j <= 100; j++)
			memo[i][j] = 0;
}

inline int maxi(int a, int b) { return a > b ? a : b; }

int main() {
	int mx = -1;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	//freopen("snipe.in", "r", stdin);
	cin >> n >> k;
	su.resize(n + 1);
	for (int i = 0; i < n; i++)
		cin >> su[i];
	for (int i = 0; i < n; i++) {
		if (su[i] & 1) {
			for (int j = 1; j <=k; j++) {
				memo[i+1][j-1] = maxi(memo[i + 1][j - 1], memo[i][j]);
				mx = maxi(mx, memo[i + 1][j - 1]);
			}
		}
		else {
			for (int j = 0; j <=k; j++) {
				memo[i + 1][j] = maxi(memo[i + 1][j], memo[i][j]+1);
				mx = maxi(mx, memo[i + 1][j]);
			}
			memo[i + 1][k] = maxi(1, memo[i + 1][k]);
		}
	}
	cout << mx << '\n';
}