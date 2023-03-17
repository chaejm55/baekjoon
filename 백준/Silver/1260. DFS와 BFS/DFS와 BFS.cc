#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;

int N;
int adj[1001][1001];
bool check[1001] = { false, };

void dfs(int V) {
	check[V] = true;
	cout << V << " ";

	for (int i = 1; i <= N; i++) {
		if (adj[V][i] == 1 && !check[i]) {
			dfs(i);
		}
	}
}

void bfs(int V)
{
	queue<int> q;
	memset(check, false, sizeof(check));

	check[V] = true;
	q.push(V);

	cout << V << " ";

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (adj[now][i] == 1 && !check[i])
			{
				check[i] = true;
				q.push(i);
				cout << i << " ";
			}
		}
	}
}

int main() {
	int M, V;
	int x, y;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	dfs(V);
	printf("\n");
	bfs(V);
}