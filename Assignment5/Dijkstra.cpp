//2017029589_RyuJibeom_509
//Dijkstra

#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <queue>

struct Vertex {
	int index;
	int dist;
};

bool operator<(Vertex u, Vertex v) {
	return u.dist > v.dist;
}

int vdata[5001];
int vsize;

std::priority_queue<Vertex> heap;
std::vector<std::vector<std::pair<int, int> > > adj;

void insert_edge(int u, int v, int dist) {
	adj[u].push_back(std::make_pair(v, dist));
}

void dijkstra(int s) {
	vdata[s] = 0;
	for (int i = 1; i <= vsize; ++i) {
		heap.push(Vertex{ i, vdata[i] });
	}

	while (!heap.empty()) {
		int index = heap.top().index;
		int dist = heap.top().dist;
		heap.pop();
		if (vdata[index] < dist) continue;
		for (int i = 0; i < adj[index].size(); ++i) {
			int n = adj[index][i].first;
			int v = adj[index][i].second;
			if (vdata[n] > dist + v) {
				vdata[n] = dist + v;
				heap.push(Vertex{ n, vdata[n] });
			}
		}
	}
}

int main(void) {
	scanf("%d", &vsize);
	adj.resize(vsize + 1);

	int vertex;
	int edgeSize;
	int distance;
	int dest;

	for (int i = 0; i < vsize; ++i) {
		scanf("%d %d", &vertex, &edgeSize);
		for (int j = 0; j < edgeSize; ++j) {
			scanf("%d %d", &dest, &distance);
			insert_edge(vertex, dest, distance);
		}
	}

	for (int i = 1; i <= vsize; ++i) {
		vdata[i] = INT_MAX;
	}

	dijkstra(1);

	int max = INT_MIN;
	for (int i = 1; i <= vsize; ++i) {
		if (vdata[i] != INT_MAX)
		{
			if (max < vdata[i])
				max = vdata[i];
		}
	}

	printf("%d", max);
}