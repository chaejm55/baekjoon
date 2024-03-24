#include <bits/stdc++.h>

using namespace std;


multiset<int> q; // 중복을 허락하는 set, 트리로 구성되며 삽입시 오름차순으로 자동정렬

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, k;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k;
		cin.get();
		for (int j = 0; j < k; j++) {
			string input;
			string command;
			int num;
			char delimiter = ' ';
			getline(cin, input);
			stringstream ss(input);
			getline(ss, command, delimiter);
			if (command == "I") {
				getline(ss, command, delimiter);
				num = stoi(command);
				q.insert(num);
			}
			else {
				getline(ss, command, delimiter);
				num = stoi(command);
				if (q.empty()) {
					continue;
				}
				else {
					if (num == -1) {
						q.erase(q.begin());
					}
					else {
						q.erase(--q.end());
					}
				}
			}
		}
		if (q.empty()) {
			cout << "EMPTY" << '\n';
		}
		else {
			cout << *(--q.end()) << ' ' << *q.begin() << '\n';
		}
		q.clear();
	}

	
	return 0;
}