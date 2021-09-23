#include<stdio.h>

int n, m;
int mt[20][200000];
int num[200000];
int tp;
bool flag;

void merge(int from, int to,int dep) {
	int lp, rp, cnt = from;
	if (from == to) {
		mt[dep][from] = num[from];
		return;
	}
	merge(from, (from + to) / 2,dep+1);
	merge((from + to) / 2 + 1, to,dep+1);
	for (lp = from, rp = (from + to) / 2 + 1; lp <= (from + to) / 2 && rp <= to;)
		if (mt[dep + 1][lp] > mt[dep + 1][rp]) mt[dep][cnt++] = mt[dep+1][rp++];
		else mt[dep][cnt++] = mt[dep + 1][lp++];
	for (; lp <= (from + to) / 2;) mt[dep][cnt++] = mt[dep + 1][lp++];
	for (; rp <= to;) mt[dep][cnt++] = mt[dep + 1][rp++];
}

void query(int node,int left, int right, int from,int to, int val) {
	if (to < left || from > right) return;
	if (from <=left && to>=right) {
		if (mt[node][right] < val) {
			tp += (right - left + 1);
			return;
		}
		else if (mt[node][left] > val) return;
		else {
			int low = left;
			int high = right;
			int mid;
			while (low<=high) {
				mid = (low + high) / 2;
				if (mt[node][mid] == val) {
					tp += mid - left;
					flag = true;
					return;
				}
				else if (mt[node][mid] > val) high = mid - 1;
				else low = mid + 1;
			}
			if (mt[node][mid] > val) tp += mid - left;
			else tp += mid - left + 1;
			return;
		}
	}
	query(node +1, left, (left + right) / 2, from, to, val);
	query(node +1, (left + right) / 2 + 1, right, from, to, val);
}

int small(int from, int to, int order) {
	int low = 1;
	int high = n;
	int mid;
	while (low <= high) {
		tp = 0;
		flag = false;
		mid = (low + high) / 2;
		query(1, 1, n, from, to, mt[1][mid]);
		if (tp == order - 1 && flag) return mt[1][mid];
		else if (tp > order - 1) high = mid - 1;
		else low = mid + 1;
	}
	return mt[1][mid];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <=n; i++) scanf("%d", &num[i]);
	merge(1,n,1);
	for (int i = 0; i < m; i++) {
		int from, to, order;
		scanf("%d%d%d", &from, &to, &order);
		printf("%d\n",small(from,to,order));
	}
}