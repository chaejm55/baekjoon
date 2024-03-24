#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string input;
    int pop_cnt = 0;
    stack<int> s;
    string answer = "";
    int n, k;

    cin >> n >> k;
    cin >> input;

    for (int i = 0; i < n; i++) {
        int num = (int)(input[i] - '0');
        while (!s.empty() && pop_cnt < k && s.top() < num) {
            pop_cnt++;
            s.pop();
        }
        s.push(num);
    }

    // 번호 마저 지우기
    while (pop_cnt < k) {
        pop_cnt++;
        s.pop();
    }
    
    while (!s.empty()) {
        answer += (char)(s.top() + '0');
        s.pop();
    }

    for (int i = answer.length() - 1; i >= 0; i--) {
        cout << answer[i];
    }

    cout << '\n';

    return 0;
}