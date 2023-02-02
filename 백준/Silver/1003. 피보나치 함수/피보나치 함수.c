#include <stdio.h>

int main() {
	int zero[41] = { 1, 0, 1, 1, }, one[41] = { 0, 1, 1, 2, };
	int T, N;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		if (N > 3) {
			for (int j = 4; j <= N; j++) {
				zero[j] = zero[j - 1] + zero[j - 2];
				one[j] = one[j - 1] + one[j - 2];
			}
		}
		printf("%d %d\n", zero[N], one[N]);
	}
}