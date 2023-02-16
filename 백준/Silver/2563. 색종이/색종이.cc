#include <bits/stdc++.h>
using namespace std;

bool paper[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    int left, bottom;
    int ans = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> left >> bottom;
        for (int k = bottom; k < bottom + 10; k++) {
            for (int j = left; j < left + 10; j++) {
                paper[k][j] = true;
            }
        }
    }

    for (int i = 1; i < 101; i++) {
        for (int j = 1; j < 101; j++) {
            if (paper[i][j] == true) {
                ans++;
            }
        }
    }

    cout << ans << '\n';


    return 0;
}

