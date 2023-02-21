#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];

int visited[100001];

int cnt = 1;

void dfs(int v);

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
        sort(graph[i].begin(), graph[i].end());
    }
    

    dfs(R);


    for (int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}

void dfs(int v) {
    visited[v] = cnt++;

    for (int i = 0; i < graph[v].size(); i++) {
        if (visited[graph[v][i]] == 0) {
            dfs(graph[v][i]);
        }
    }
}