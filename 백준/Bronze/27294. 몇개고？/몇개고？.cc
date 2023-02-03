#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, S;
    int ans;
    cin >> T >> S;
    if (S == 1) {
        ans = 280;
    }
    else {
        if (T <= 11) {
            ans = 280;
        }
        else if (T >= 12 && T <= 16) {
            ans = 320;
        }
        else {
            ans = 280;
        }
    }
    cout << ans << '\n';
}