#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int cnt;
	int K;
	cin >> cnt >> K;
	queue<int>q;
	for (int i = 0; i < cnt; i++)
		q.push(i + 1);
	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < K - 1; i++) {
			int x = q.front();
			q.pop();
			q.push(x);
		}
		if (q.size() == 1)cout << q.front();
		else cout << q.front() << ", ";
		q.pop();
	}
	cout << ">";
}