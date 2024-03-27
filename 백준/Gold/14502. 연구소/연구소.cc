#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

#define pii pair<int, int>
#define pss pair<short, short>

using namespace std;

int board[8][8];
int board_copy[8][8];
bool visited[8][8];
pss mv[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int n, m;
int cnt_0, cnt_2;
int answer = -1;

int bfs(int y, int x) {
    queue<pii> q;
    int bfs_cnt_2 = 0;

    q.push({ y, x });
    visited[y][x] = true;


    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + mv[i].first;
            int nx = cx + mv[i].second;
            if (visited[ny][nx] == false && board_copy[ny][nx] != 1 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
                if (board_copy[ny][nx] == 0) {
                    bfs_cnt_2++;
                }
                visited[ny][nx] = true;
                board_copy[ny][nx] = 2;
                q.push({ ny, nx });
            }
        }
    }
    return bfs_cnt_2;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

    vector<pii> zero;
    vector<pii> virus;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                cnt_0++;
                zero.push_back({ i, j });
            }
            else if (board[i][j] == 2) {
                virus.push_back({ i, j });
                cnt_2++;
            }
        }
    }

    vector<bool> wall(cnt_0, false);

    for (int i = 0; i < 3; i++) { // 순열 생성을 위해 true 3개로 벽 설정
        wall[i] = true;
    }

    sort(wall.begin(), wall.end()); 
    
    do {
        memcpy(board_copy, board, sizeof(board));
        memset(visited, false, sizeof(visited));

        int bfs_cnt_2 = 0;

        for (int i = 0; i < cnt_0; i++) {
            if (wall[i] == true) {
                board_copy[zero[i].first][zero[i].second] = 1;
            }
        }

        for (auto v : virus) {
            bfs_cnt_2 += bfs(v.first, v.second);
        }


        answer = max(answer, cnt_0 - 3 - bfs_cnt_2); // 원래 0 개수에서 벽 개수 3개, 감염된 수만큼 빼기

    } while (next_permutation(wall.begin(), wall.end())); // 벽 3개를 순열로 만들기
    
    cout << answer << '\n';


    return 0;
}