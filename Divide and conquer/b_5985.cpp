/*
https://www.acmicpc.net/problem/5985
john �� 2^n(1<= n <=10) ������ �Ұ� �ִ�. �� �ҿ��� ��ȣ�� ���� ������ ������� �� ������ �ʴ�.
�״� �ҵ��� ������� ��ġ�ϱ� ���� ������ ���� �˰����� ����ߴ�.
1. �Ұ� �Ѹ����� �ʰ��Ѵٸ� �ҵ��� �ΰ��� ���� �׷����� �����ϰ�, �� �׷�鿡�� �� �˰����� Ȱ���Ѵ�.
2. ��ĥ���� �տ� �ִ°� �������� ��°�� �����Ѵ�.
���� ������Ʈ ���� �� �� ��尡 �� �̵��� Ƚ���� �� ��尡 �̵��� ��ȣ�� ����ϸ� �� �� �ϴ�.
Ƽ��� �ǹ� 4
*/

#include<iostream>
#include<vector>

using namespace std;


int n, length;
vector<int> cows;

int po(int p) {
	int rst = 1;
	for (; p && rst; p--, rst *= 2);
	return rst;
}

int merge(int lo, int hi) {
	int tot = 0,mi=(hi+lo)/2,len = hi-lo+1,idx = 0;
	vector<int> temp(len);
	if(hi-lo>1) tot += merge(lo, mi) + merge(mi +1, hi);
	if (cows[lo] > cows[mi + 1]) {
		for (int m = mi+1; m <= hi; m++) temp[idx++] = cows[m];
		for (int l = lo; l <= mi; l++) temp[idx++] = cows[l];
		tot += len*len/2;
	}
	else {
		for (int l = lo; l <= mi; l++) temp[idx++] = cows[l];
		for (int m = mi+1; m <= hi; m++) temp[idx++] = cows[m];
	}
	for (int idx = 0; lo+idx <= hi; idx++) cows[lo+idx] = temp[idx];
	return tot;
}

int main() {
	cin >> n;
	length = po(n);
	cows.resize(length);
	for (int i = 0; i < length; i++) cin >> cows[i];
	cout << merge(0,length-1) << endl;
	for (int cowId:cows) cout << cowId << endl;
}