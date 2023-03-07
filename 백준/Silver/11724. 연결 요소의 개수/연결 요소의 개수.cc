#include <bits/stdc++.h>

using namespace std;

queue<int> q;

vector<int> graph[1001];

bool visited[1001];

void bfs(int v);

int cnt = 0;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            bfs(i);
        }
    }

    cout << cnt << '\n';

    return 0;
}

void bfs(int v) {
    cnt++;
    visited[v] = true;
    q.push(v);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            if (visited[graph[cur][i]] == false) {
                visited[graph[cur][i]] = true;
                q.push(graph[cur][i]);
            }
        }
    }
}