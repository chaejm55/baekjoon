#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <climits>

#define pii pair<int, int>
#define pss pair<short, short>

using namespace std;

int n, answer;
int board[20][20];
bool visited[20][20];
int dist[20][20];
pss mv[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int shark_size = 2;
int eat_cnt = 0;

void bfs(int y, int x) {
    queue<pii> q;
    q.push({ y, x });
    visited[y][x] = true;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + mv[i].first;
            int nx = cx + mv[i].second;
            if (visited[ny][nx] == false && board[ny][nx] <= shark_size && ny >= 0 && ny < n && nx >= 0 && nx < n) { // 자기보다 작거나 같은 칸만 이동
                visited[ny][nx] = true;
                dist[ny][nx] = dist[cy][cx] + 1; // 최단거리 저장
                // cout << ny << ", " << nx << '\n';
                q.push({ ny, nx });
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    vector<pii> fish[7];
    pii shark_position;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 6) {
                fish[board[i][j]].push_back({ i, j }); // 물고기 위치 크기 별로 저장
            }
            else if (board[i][j] == 9) {
                shark_position = { i, j }; // 초기 위치 설정
                board[i][j] = 0; // 방문 완료
            }
        }
    }

    while (true) {
        memset(visited, false, sizeof(visited));
        memset(dist, 0, sizeof(dist));

        int distance = INT_MAX;
        bool isEnd = true;

        bfs(shark_position.first, shark_position.second);
        for (int i = 1; i < shark_size; i++) {
            if (i > 6) { // 크기가 7인 물고기는 없음
                break;
            }
            for (auto f : fish[i]) {
                if (board[f.first][f.second] != 0) { // 먹을 수 있는 물고기가 존재
                    if (dist[f.first][f.second] == distance && f < shark_position) { // 최단거리 물고기 중에 더 위, 왼쪽 물고기가 있다면
                        shark_position = f; // 상어 위치 갱신
                        // cout << dist[f.first][f.second] << ", " << distance << '\n';
                    }
                    if (dist[f.first][f.second] > 0 && dist[f.first][f.second] < distance) { // 새로운 최단거리를 발견했다면
                        isEnd = false;
                        distance = dist[f.first][f.second];
                        shark_position = f;
                    }
                }
            }
        }
        if (isEnd == true) { // 먹을 수 있는 물고기를 못 찾음
            break;
        }
        board[shark_position.first][shark_position.second] = 0; // 물고기 먹기 완료
        eat_cnt++;
        if (eat_cnt == shark_size) { // 상어크기 증가
            eat_cnt = 0;
            shark_size++;
        }
        answer += distance;
        // cout << "(" << shark_position.first << ", " << shark_position.second << ") " << distance << " " << answer << '\n';
    }

    if (answer == INT_MAX) { // 아무 물고기도 못먹는 경우
        answer = 0;
    }

    cout << answer << '\n';

    return 0;
}