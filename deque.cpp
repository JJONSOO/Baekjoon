//백준 10866번 문제
//풀이 : deque 사용법 익히기
#include<iostream>
#include<string>
#include<deque>
using namespace std;
deque<int> d;
void push_front(int x) {
	d.push_front(x);
}
void push_back(int x) {
	d.push_back(x);
}
void pop_front() {
	if (d.empty())cout << -1 << endl;
	else {
		cout << d.front() << endl;
		d.pop_front();
	}
}
void pop_back() {
	if (d.empty())cout << -1 << endl;
	else {
		cout << d.back() << endl;
		d.pop_back();
	}
}
void front() {
	if (d.empty())cout << -1 << endl;
	else cout <<d.front() << endl;
}
void back() {
	if (d.empty())cout << -1 << endl;
	else cout << d.back() << endl;
}
int main() {
	int cnt;
	cin >> cnt;
	while (cnt--) {
		string str;
		cin >> str;
		if (str == "push_front") {
			int c;
			cin >> c;
			push_front(c);
		}
		if (str == "push_back") {
			int c;
			cin >> c;
			push_back(c);
		}
		if (str == "pop_front") {
			pop_front();
		}
		if (str == "pop_back") {
			pop_back();
		}
		if (str == "size") {
			cout << d.size() << endl;
		}
		if (str == "empty") {
			if (d.empty())cout << 1 << endl;
			else cout << 0 << endl;
		}
		if (str == "front") {
			front();
		}
		if (str == "back") {
			back();
		}

	}
}