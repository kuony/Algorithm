#include<stdio.h>

int arr[500001];
int tmp[500001];
int n;
long long int ans;

void merge(int left, int right) {
	if (left == right) return;
	merge(left, (left + right) / 2);
	merge((left + right) / 2 +1, right);
	int lp, rp, cnt;
	for (cnt =lp = left,rp = (left+right)/2+1;lp <= (right+left)/2 && rp<= right; cnt++) {
		if (arr[lp] > arr[rp]) {
			tmp[cnt] = arr[rp++];
			ans += (right+left)/2 - lp +1;
		}
		else tmp[cnt] = arr[lp++];
	}
	for (;lp <= (right + left) / 2; lp++)tmp[cnt++] = arr[lp];
	for (;rp <= right; rp++)tmp[cnt++] = arr[rp];
	for (int i = left; i <= right; i++) arr[i] = tmp[i];
}

int main() {
	int n,x,i;
	for (scanf("%d", &n),i=1;i<=n;i++) {
		scanf("%d", &arr[i]);
	}
	merge(1,n);
	printf("%lld", ans);

}