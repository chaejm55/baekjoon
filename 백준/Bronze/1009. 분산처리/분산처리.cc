#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    int a, b;
    int ans;
    cin >> T;
    for (int k = 0; k < T; k++) {
        cin >> a >> b;
        ans = 1;
        for (int i = 0; i < b; i++) {
            ans *= a;
            ans %= 10;
        }
        if (ans == 0) {
            ans = 10;
        }
        cout << ans << '\n';
    }
}