#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> q;

char graph[101][101];

bool visited[101][101];
bool rg_visited[101][101];

pair<short, short> mv[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int cnt = 0;
int rg_cnt = 0;

void bfs(int y, int x);
void rg_bfs(int y, int x);

int N;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char input;
            cin >> input;
            graph[i][j] = input;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == false) {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rg_visited[i][j] == false) {
                rg_bfs(i, j);
            }
        }
    }

    cout << cnt << ' ' << rg_cnt << '\n';

    return 0;
}

void bfs(int y, int x) {
    cnt++;
    visited[y][x] = true;
    q.push({y, x});
    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        char cur_symbol = graph[cur_y][cur_x];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + mv[i].first;
            int next_x = cur_x + mv[i].second;
            if (next_y >= 0 && next_x >= 0 && next_y < N && next_x < N && graph[next_y][next_x] == cur_symbol && visited[next_y][next_x] == false) {
                visited[next_y][next_x] = true;
                q.push({next_y, next_x});
            }
        }
    }
}

void rg_bfs(int y, int x) {
    rg_cnt++;
    rg_visited[y][x] = true;
    q.push({y, x});
    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        char cur_symbol = graph[cur_y][cur_x];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + mv[i].first;
            int next_x = cur_x + mv[i].second;
            if (cur_symbol == 'B') {
                if (next_y >= 0 && next_x >= 0 && next_y < N && next_x < N && graph[next_y][next_x] == cur_symbol && rg_visited[next_y][next_x] == false) {
                    rg_visited[next_y][next_x] = true;
                    q.push({next_y, next_x});
                }
            }
            else {
                if (next_y >= 0 && next_x >= 0 && next_y < N && next_x < N && (graph[next_y][next_x] == 'R' || graph[next_y][next_x] == 'G') && rg_visited[next_y][next_x] == false) {
                rg_visited[next_y][next_x] = true;
                q.push({next_y, next_x});
                }
            }
        }
    }
}