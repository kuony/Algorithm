/*
5*5  �׸���� �Ǿ��ִ� �� �Ʒ��� ������ ö ����� ũ����Ż�� �ִ�.
���̰� ������ �ø����� 5�� ���������� Ŀ����, Ƣ����ִ� 3���� �鿡 
�Ȱ��� �������� ������ ö ����� ũ����Ż ������ �����ȴ�.
�׽�Ʈ���̽��� �Է� �� ������ ss��ǥ�� �Էµ� ������ ũ����Ż�� �ִ��� ����ִ���
����ϸ� �ȴ�.

����.. �׳� ������ ������ ������ ���̸� �򰥸����� �𸣰ڴ�.
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