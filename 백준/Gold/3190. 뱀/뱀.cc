#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define pic pair<int, char>

using namespace std;

int board[101][101];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    int n, k, l; 
    int answer = 0;
    cin >> n >> k;
    queue<pii> snake;
    queue<pic> direction;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> y >> x;
        board[y][x] = 1;
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int sec;
        char dir;
        cin >> sec >> dir;
        direction.push({ sec, dir });
    }

    snake.push({ 1, 1 });
    board[1][1] = -1;

    pii move[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    short cur_move = 0;
    int next_y, next_x;

    while (1) {
        next_y = snake.back().first + move[cur_move].first;
        next_x = snake.back().second + move[cur_move].second;
        answer++;
        // cout << "(" << answer << "초) " << next_y << ", " << next_x << "(" << snake.size() << ")\n";
        if (next_x > n || next_x < 1 || next_y > n || next_y < 1) { // 보드 끝에 닿음
            break;
        }
        if (board[next_y][next_x] == -1) { // 자기 몸에 닿음
            break;
        }

        if (board[next_y][next_x] == 0) { // 꼬리 자르기
            board[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }

        if (board[next_y][next_x] == 1) { // 먹은 사과 지우기
            board[next_y][next_x] = 0;
        }


        if (!direction.empty()) {
            if (direction.front().first == answer) {
                if (direction.front().second == 'D') {
                    cur_move = (cur_move + 1) % 4;
                }
                else {
                    cur_move = (cur_move + 3) % 4;
                }
                direction.pop();
            }
        }
        board[next_y][next_x] = -1;
        snake.push({ next_y, next_x });
    }

    cout << answer << '\n';

    return 0;
}