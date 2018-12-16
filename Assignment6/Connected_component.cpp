//2017029589_RyuJibeom_509
//Conneted_component

#include <stdio.h>
#include <algorithm>
#include <vector>

int vdata[1001];
int adj[1001][1001];
int visited[1001];
int com[1001];

int vsize;
int component = 0;

void DFS(int v) {
	for (int w = 1; w <= vsize; ++w) {
		if (adj[v][w] != 0 && visited[w] == 0) {
			com[w] = component;
			visited[w] = 1;
			DFS(w);
		}
	}
}

int main(void) {
	int x, y;
	scanf("%d", &vsize);

	while (~scanf("%d %d", &x, &y)) {
		adj[x][y] = adj[y][x] = 1;
	}

	for (int i = 1; i <= vsize; ++i) {
		if (visited[i] == 0) {
			++component;
			com[i] = component;
			DFS(i);
		}
	}

	printf("%d\n", component);
	for (int i = 1; i <= vsize; ++i) {
		printf("%d\n", com[i]);
	}
}