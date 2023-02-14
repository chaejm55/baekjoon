#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];

queue<int> q;

int visited[100001];

int cnt = 1;

void bfs(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, R;

    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    bfs(R);

    for (int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}

void bfs(int start) {
    visited[start] = cnt++;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            if (!visited[graph[cur][i]]) {
                visited[graph[cur][i]] = cnt++;
                q.push(graph[cur][i]);
            }
        }
    }
}