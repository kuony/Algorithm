#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int n, arr[1000001];
vector<vector<int> > vec;

int main() {
	scanf("%d", &n);
	vec.resize(n+1);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		arr[x] = i;
	}
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec[i].push_back(arr[x]);
	}
}