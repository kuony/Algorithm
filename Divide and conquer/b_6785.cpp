/*
5*5  그리드로 되어있는 판 아래에 볼록할 철 모양의 크리스탈이 있다.
현미경 배율을 올릴수록 5의 지수승으로 커지며, 튀어나와있는 3개의 면에 
똑같은 패턴으로 볼록할 철 모양의 크리스탈 패턴이 생성된다.
테스트케이스를 입력 후 배율과 ss좌표가 입력될 때마다 크리스탈이 있는지 비어있는지
출력하면 된다.

아잇.. 그냥 간단한 문젠데 수식이 왜이리 헷갈리는지 모르겠다.
*/

#include<iostream>

using namespace std;

int x, y;

int po(int p) {
	int rst = 1;
	for (; p && rst; p--, rst *= 5);
	return rst;
}

bool isCrystal(int m,int sx, int sy) {
	int d = po(m);
	if ((x >= sx + d && x <= sx + 4 * d -1) && (y <= sy + d -1)) return true;
	else if ((x >= sx + 2 * d && x <= sx + 3 * d -1) && (y <= sy + 2 * d -1)) return true;
	return false;
}

bool cantBeCrystal(int m, int sx, int sy) {
	int d = po(m);
	if ((x >= sx + d && x <= sx + 4 * d -1) && (y <= sy + 2*d -1)) return false;
	else if ((x >= sx + 2*d && x <= sx + 3 * d -1) && (y <= sy + 3*d -1)) return false;
	return true;
}

bool loop(int m, int sx, int sy){
	for (;m; m--) {
		int d = po(m);
		if (isCrystal(m, sx, sy)) return true;
		if (cantBeCrystal(m, sx, sy)) return false;
		if ((x >= sx + d && x <= sx + 2 * d -1) && (y <= sy + 2* d -1 && y >= sy + d)){
			sx = sx + d;
			sy = sy + d;
		}
		else if ((x >= sx + 2* d && x <= sx + 3 * d -1) && (y <= sy + 3 * d -1 && y >= sy + 2* d)) {
			sx = sx + 2* d;
			sy = sy + 2* d;
		}
		else {
			sx = sx + 3 * d;
			sy = sy + 1 * d;
		}
	}
	if (isCrystal(m, sx, sy)) return true;
	return false;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int m;
		cin >> m >> x >> y;
		if (loop(m-1, 0, 0)) cout << "crystal" << endl;
		else cout << "empty" << endl;
	}
}