/*
https://www.acmicpc.net/problem/1509
���ڿ��� ������ �Է¹޾Ƽ� �Ӹ�������� �����ϴ� �����̴�.
������ �ּ� ������ �Ӹ�������� ���ҵ��� �� �� ���� ����Ѵ�.
�Է� ���ڿ� �ִ� ���̴� 2500 �̴�.
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;


string input;
vector<char> str;
int ans;

int main() {
	cin >> input;
	for (char iter:input) {
		str.push_back('#');
		str.push_back(iter);
	}
	str.push_back('#');
}