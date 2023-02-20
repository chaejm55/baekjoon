#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, F;
    int ans;

    cin >> N >> F;

    int temp = N - (N % 100);
    for (int i = 0; i < 100; i++, temp++) {
        if (temp % F == 0) {
            ans = i;
            break;
        }
    }

    cout.width(2);
    cout.fill('0');
    cout << ans << '\n';


    return 0;
}

