#include<stdio.h>

typedef long long lld;

int n;
lld sg[1 << 21];
int pivot = 1 << 20;

int query(int node,int left, int right,int val) {
	if (left == right) return node-pivot+1;
	if (sg[node * 2] < val) 
		return  query(node * 2 + 1, (left + right) / 2 + 1, right, 
			val - sg[node * 2]);
	return query(node*2,left,(left+right)/2,val);
}

void update(int idx,lld val) {
	sg[idx] += val;
	idx >>= 1;
	while (idx) {
		sg[idx] = sg[idx * 2] + sg[idx * 2 + 1];
		idx >>= 1;
	}
}

int main() {
	int flag,x,y;
	int ans;
	for (scanf("%d", &n); n--;) {
		scanf("%d", &flag);
		if (!(flag & 1)) {
			scanf("%d%d", &x, &y);
			update(x + pivot - 1, y);
			continue;
		}
			scanf("%d", &ans);
			ans = query(1, 1, pivot, ans);
			printf("%d\n", ans);
			update(ans+pivot-1,-1);
	}
}