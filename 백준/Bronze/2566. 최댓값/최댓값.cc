#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int arr[9][9] = {0, };
    int max = -1;
    int y = 0, x = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
                y = i + 1;
                x = j + 1;
            }
        }
    }
    cout << max << '\n';
    cout << y << ' ' << x << '\n';
}