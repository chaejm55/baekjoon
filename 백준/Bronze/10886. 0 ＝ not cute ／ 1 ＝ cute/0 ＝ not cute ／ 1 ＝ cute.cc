#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    int cute = 0, not_cute = 0;
    int input;
    cin >> T;
    for (int k = 0; k < T; k++) {
        cin >> input;
        if (input == 1) {
            cute++;
        }
        else {
            not_cute++;
        }
    }

    if (cute > not_cute) {
        cout << "Junhee is cute!" << '\n';
    }
    else {
        cout << "Junhee is not cute!" << '\n';
    }
}