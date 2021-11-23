#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int cnt;
	cin >> cnt;
	while (cnt--) {
		queue<int> q;
		string str;
		cin >> str;
		int open = 0;
		int close = 0;
		bool check = true;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				q.push(str.at(i));
				open++;
			}
			else {
				close++;
				if (q.empty()||q.front() == str.at(i)||close>open) {
					cout << "NO\n";
					check = false;
					break;
				}
				else {
					q.push(str.at(i));
				}

			}
		}
		if (check) {
			if (open == close) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
	}

}