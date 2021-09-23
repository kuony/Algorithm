#include<stdio.h>

struct t {
	int val;
	int idx;
};

template <class T> class queue {
	int front = 0;
	int rear = 0;
	T arr[200001];
public:
	T frnt() { return arr[front]; }
	void pop() { front++; }
	void push(T x) { arr[rear++] = x; }
	bool empty() { return front == rear ? true : false; }
};

typedef unsigned long long int lld;

const int inf = 1000001;
t minst[1 << 18];
lld sumst[1 << 18];
int pivot = 1 << 17, n;
lld ans;
queue<t> q;

inline t small(t x, t y) { return x.val > y.val ? y : x; }
inline lld bi(lld x, lld y) { return x > y ? x : y; }



void update(int idx, int val) {
	minst[idx].val = val;
	minst[idx].idx = idx - pivot + 1;
	sumst[idx] = val;
	idx >>= 1;
	while (idx) {
		sumst[idx] = sumst[idx * 2] + sumst[idx * 2 + 1];
		minst[idx] = small(minst[idx * 2], minst[idx * 2 + 1]);
		idx >>= 1;
	}
}

t mquery(int node, int left, int right, int from, int to) {
	if (left > to || right < from) return { inf,0 };
	if (from <= left && right <= to) return minst[node];
	return small(mquery(node * 2, left, (left + right) / 2, from, to)
		, mquery(node * 2 + 1, (left + right) / 2 + 1, right, from, to));
}

lld squery(int node, int left, int right, int from, int to) {
	if (left > to || right < from) return 0;
	if (from <= left && right <= to) return sumst[node];
	return squery(node * 2, left, (left + right) / 2, from, to) +
		squery(node * 2 + 1, (left + right) / 2 + 1, right, from, to);
}

void big(int from, int to) {
	q.push({ from,to });
	while (!q.empty()) {
		from = q.frnt().val;
		to = q.frnt().idx;
		q.pop();
		if (from > to) continue;
		t tmp = mquery(1, 1, pivot, from, to);
		ans = bi(ans, tmp.val * squery(1, 1, pivot, from, to));
		q.push({ from, tmp.idx - 1 });
		q.push({ tmp.idx + 1, to });
	}
}

int main() {
	int x;
	scanf("%d", &n);
	for (int i = 0; i < 1 << 18; i++)  minst[i].val = inf;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		update(pivot + i, x);
	}
	big(1, n);
	printf("%lld", ans);
}