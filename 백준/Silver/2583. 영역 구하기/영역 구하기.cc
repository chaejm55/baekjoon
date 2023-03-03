#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;

int visited[100][100];

vector<int> ans;

pair<short, short> mv[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int M, N, K;

int cnt = 0;

void bfs(int y, int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j < y2; j++) {
            for (int k = x1; k < x2; k++) {
                visited[j][k] = -1; // 사각형으로 채워지는 범위
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0) {
                bfs(i, j);
            }
        }
    }

    cout << cnt << '\n';
    sort(ans.begin(), ans.end());
    for (int i = 0; i < cnt; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}

void bfs(int y, int x) {
    int width = 0;
    cnt++;
    
    visited[y][x] = 1;
    width++;
    q.push({y, x});

    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + mv[i].first;
            int next_x = cur_x + mv[i].second;
            if (next_y < M && next_x < N && next_x >= 0 && next_y >= 0 && visited[next_y][next_x] == 0) {
                visited[next_y][next_x] = 1;
                width++;
                q.push({ next_y, next_x });
            }
        }
    }
    ans.push_back(width);
}