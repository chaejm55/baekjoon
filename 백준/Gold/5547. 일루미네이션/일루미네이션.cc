#include <iostream>
#include <string>
#include <queue>

#define MOVE_SIZE 6

using namespace std;


bool visited[102][102];
int v[102][102]; // 가상의 바깥쪽 외벽 생성

pair<short, short> odd_mv[MOVE_SIZE] = { {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 0}, {0, -1} };
pair<short, short> even_mv[MOVE_SIZE] = { {0, -1}, {1, 0}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1} };

int w, h;

void bfs_wall(int y, int x) {
    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = true;

    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for (int i = 0; i < MOVE_SIZE; i++) {
            int next_y, next_x;
            if (cur_y % 2 != 0) {
                next_y = cur_y + odd_mv[i].second;
                next_x = cur_x + odd_mv[i].first;
            }
            else {
                next_y = cur_y + even_mv[i].second;
                next_x = cur_x + even_mv[i].first;
            }
            if (v[next_y][next_x] == 0 && visited[next_y][next_x] == false && next_y >= 0 && next_y <= h + 1 && next_x >= 0 && next_x <= w + 1) { // 가상 외벽 포함해서 구하기
                visited[next_y][next_x] = true;
                v[next_y][next_x] = -1;
                q.push({ next_y, next_x });
            }
        }
    }
}

int bfs_light(int y, int x) {
    int light = 0;
    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = true;

    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for (int i = 0; i < MOVE_SIZE; i++) {
            int next_y, next_x;
            if (cur_y % 2 != 0) {
                next_y = cur_y + odd_mv[i].second;
                next_x = cur_x + odd_mv[i].first;
            }
            else {
                next_y = cur_y + even_mv[i].second;
                next_x = cur_x + even_mv[i].first;
            }
            if (v[next_y][next_x] == -1) {
                light++;
            }
            if (v[next_y][next_x] == 1 && visited[next_y][next_x] == false && next_y >= 1 && next_y <= h && next_x >= 1 && next_x <= w) {
                visited[next_y][next_x] = true;
                q.push({ next_y, next_x });
            }
        }
    }
    return light;
}


int main() {
    cin >> w >> h;
    int answer = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> v[i][j];
        }
    }

    bfs_wall(0, 0);

    /*
    for (int i = 0; i <= h + 1; i++) {
        for (int j = 0; j <= w + 1; j++) {
            cout.width(3);
            cout << v[i][j] << " ";
        }
        cout << endl;
    }*/

    /*
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (v[i][j] == 0) {
                int wall_cnt = 0;
                // 조명을 달지 않는 내부 -1로 표시
                for (int k = 0; k < MOVE_SIZE; k++) {
                    int next_y, next_x;
                    if (i % 2 == 0) {
                        next_y = i + odd_mv[k].second;
                        next_x = j + odd_mv[k].first;
                    }
                    else {
                        next_y = i + even_mv[k].second;
                        next_x = j + even_mv[k].first;
                    }
                    if (v[next_y][next_x] == 1) {
                        wall_cnt++;
                    }
                }
                if (wall_cnt == 6) {
                    cout << i << " " << j << '\n';
                    v[i][j] = -1;
                }
            }
        }
    }
    */

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (v[i][j] == 1 && visited[i][j] == false) {
                answer += bfs_light(i, j);
            }
        }
    }
    cout << answer << '\n';

    return 0;
}