#include<iostream>
#include<cstdio>

using namespace std;

struct par {
	int x;
	int y;
};

template <class T>class queue {
private:
	T arr[1000000];
	int frnt;
	int rear;
public:
	queue() {
		frnt = 0;
		rear = 0;
	}
	void push(T x) {
		this->arr[this->rear] = x;
		this->rear += 1;
	}
	void pop() { this->frnt += 1; }

	T front() {
		return this->arr[this->frnt];
	}
	bool empty() {
		return frnt == rear;
	}
};

int mov[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int map[101][101];
bool vs[101][101];
int n;

int bfs(int x,int y) {
	queue<par> que;
	que.push({x,y});
	while (!que.empty()) {
		par tmp = que.front();
		if (vs[tmp.x][tmp.y]) continue;
		vs[tmp.x][tmp.y] = true;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int dx = tmp.x + mov[i][0];
			int dy = tmp.y + mov[i][1];
			if (dx >= 0 && dy>=0 && dx < n && dy< n) {
				que.push({ dx,dy });
			}
		}
	}
	return 0;
}

int main() {
	for(int i =0;i<n;i++)
		for (int j = 0; j < n; j++) {

		}
}