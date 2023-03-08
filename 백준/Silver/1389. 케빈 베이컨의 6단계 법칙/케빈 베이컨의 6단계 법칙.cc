#include <bits/stdc++.h>

using namespace std;

queue<int> q;

vector<int> graph[101];

int visited[101];

vector<int> bacon(101);

void bfs(int v);


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
        bfs(i);
    }

    cout << min_element(bacon.begin() + 1, bacon.begin() + N) - bacon.begin() << '\n';

    return 0;
}

void bfs(int v) {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
    visited[v] = 1;
    q.push(v);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            if (visited[graph[cur][i]] == 0) {
                visited[graph[cur][i]] = visited[cur] + 1;
                q.push(graph[cur][i]);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        bacon[v] += visited[i];
    }
}