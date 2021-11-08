/*
https://www.acmicpc.net/problem/5985
john 은 2^n(1<= n <=10) 마리의 소가 있다. 각 소에는 번호가 써져 있지만 순서대로 서 있지는 않다.
그는 소들을 순서대로 배치하기 위해 다음과 같은 알고리즘을 고안했다.
1. 소가 한마리를 초과한다면 소들을 두개의 하위 그룹으로 분할하고, 각 그룹들에도 이 알고리즘을 활용한다.
2. 합칠때는 앞에 있는것 기준으로 통째로 스왑한다.
대충 머지소트 구현 후 각 노드가 총 이동한 횟수랑 각 노드가 이동한 번호를 출력하면 될 듯 하다.
티어는 실버 4
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