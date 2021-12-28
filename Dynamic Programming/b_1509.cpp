/*
https://www.acmicpc.net/problem/1509
문자열이 들어오면 입력받아서 팰린드롬으로 분할하는 문제이다.
문자이 최소 개수의 팰린드롬으로 분할됐을 때 그 수를 출력한다.
입력 문자열 최대 길이는 2500 이다.

한참을 삽질하다가 블로그에서 다익스트라를 썼다는 힌트를 보고 나서야 풀었다.
세상에... 이렇게나 쉬운 문제였다니

*/

#include<iostream>
#include<vector>
#include<string>
#include<time.h>

using namespace std;

const int maxlen = 2500;
const int inf = 120000;

int n;
int cnt;
int dist[maxlen][maxlen];
string target;

void init() {
	for (int i = 0; i < maxlen; i++)
		for (int j = 0; j < maxlen; j++) {
			if (j-i == 1)
				dist[i][j] = 2;
			else dist[i][j] = (i == j) ? 1 : inf;
		}
}

void isFel(int from, int to) {
	for (int i = from; i <= to; i++) {
		int left = i - 1, right = i + 1;
		for (; left >= from && right <= to; left--, right++) {
			if (target[left] == target[right]) {
				dist[left][right] = 1;
			}
			else
				break;
		}
		if (target[i]==target[i+1]) {
			int left = i - 1, right = i + 2;
			dist[i][i + 1] = 1;
			for (; left >= from && right <= to; left--, right++) {
				if (target[left] == target[right]) {
					dist[left][right] = 1;
				}
				else
					break;
			}
		}
		
	}
}

int dijkstra(int from, int to) {
	for (int i = from; i <to; i++) {
		if (dist[from][i] == inf) continue;
		for (int j = i; j <=to; j++) {
			if (dist[from][j] > dist[from][i] + dist[i+1][j]) {
				dist[from][j] = dist[from][i] + dist[i+1][j];
			}
		}
	}
	return dist[from][to];
}

int main() {
	cin >> target;
	n = target.length();
	init();
	isFel(0,n-1);
	cout << dijkstra(0,n-1);
}

/*
뻘짓... 시간초과난다. 약 5000ms
bool findDiv(int from, int to, int amount) {
	if (minFel[from][to] != maxlen+1)
		return minFel[from][to];
	else if (amount == 1) {
		if (Fel[from][to]) {
			minFel[from][to] = amount;
			return true;
		}
	}
	else if (amount == 2) {
		for (int i = from; i < to; i++) {
			if (target[i] == target[from] && target[i + 1] == target[to])
				if (Fel[from][i] && Fel[i+1][to]) {
					minFel[from][to] = amount;
					return true;
				}
		}
	}
	else{
		for (int i = from; i < to-1; i++) {
			if (target[i] != target[from]) continue;
			if (Fel[from][i]) continue;
			for (int j = to; j > i+1; j--) {
				if (target[j] != target[to]) continue;
				if (!Fel[j][to]) continue;
				if (findDiv(i + 1, j - 1, amount - 2)) {
					minFel[from][to] = amount;
					return true;
				}
			}
		}
	}

	return false;
}

int main() {
	bool flag = true;
	clock_t start;
	cin >> target;
	start = clock();
	n = target.length();
	init();
	isFel(0,n-1);
	for (int i = 1; i < n; i++) {
		if (findDiv(0, n - 1, i)) {
			cout << i << endl;
			flag = false;
			break;
		}
	}
	if (flag) cout << 1 << endl;
	cout << clock() - start << endl;
	cout << cnt;
}
*/
