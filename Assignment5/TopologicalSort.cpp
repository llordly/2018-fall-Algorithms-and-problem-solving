//2017029589_RyuJibeom_509
//Topological Sort
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

int adj[1000][1000];

int vsize = 0;
int time = 0;

int acycle = 1;

typedef std::pair<int, int> pair;
std::vector<pair> visited(1000);

bool comparator(const pair &l, const pair &r) {
	return l.second > r.second;
}

void insert_edge(int u, int v) {
	adj[u][v] = 1;
}

void DFS(int v) {
	++time;
	visited[v].second = -1;

	for (int w = 1; w <= vsize; ++w) {
		if (adj[v][w] != 0) {
			if (visited[w].second == 0) {
				DFS(w);
			}
			else if (visited[w].second == -1){
				acycle = 0;
			}
		}
	}
	visited[v].second = ++time;
}

int main(void) {

	int u, v;
	scanf("%d", &vsize);
	for (int i = 1; i <= vsize; ++i) {
		visited[i].first = i;
		visited[i].second = 0;
	}

	while (~scanf("%d %d", &u, &v)) {
		insert_edge(u, v);
	}

	for (int i = 1; i <= vsize; ++i) {
		if (visited[i].second == 0)
			DFS(i);
	}

	if (acycle) {
		printf("1\n");
		std::sort(visited.begin() + 1, visited.begin() + vsize + 1, comparator);
		for (int i = 1; i <= vsize; ++i) {
			printf("%d ", visited[i].first);
		}
	}
	else {
		printf("0");
	}

	return 0;
}