/*
https://www.acmicpc.net/problem/1509
문자열이 들어오면 입력받아서 팰린드롬으로 분할하는 문제이다.
문자이 최소 개수의 팰린드롬으로 분할됐을 때 그 수를 출력한다.
입력 문자열 최대 길이는 2500 이다.
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