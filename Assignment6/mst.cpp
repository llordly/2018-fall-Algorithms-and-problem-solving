//2017029589_RyuJibeom_509
//mst

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>

struct Vertex {
	int v1;
	int v2;
	int weight;
};

bool operator<(Vertex u, Vertex v) {
	if (u.weight == v.weight) {
		if (u.v1 == v.v1) {
			return u.v2 > v.v2;
		}
		else
			return u.v1 > v.v1;
	}
	else
		return u.weight > v.weight;
}

std::priority_queue<Vertex> heap;
int adj[1001][1001];
int result[1001][3];

void insert_edge(int u, int v, int weight) {
	adj[u][v] = adj[v][u] = weight;
}

int parent[1001];
int set_size;
int vsize;

void init_set(int nSets) {
	set_size = nSets;
	for (int i = 0; i < nSets; ++i) {
		parent[i] = -1;
	}
}

int find_set(int id) {
	while (parent[id] >= 0)
		id = parent[id];
	return id;
}

void union_set(int s1, int s2) {
	parent[s1] = s2;
	set_size--;
}

int Kruskal() {
	int i, j, edgeAccepted = 0, uset, vset;
	Vertex e;
	init_set(vsize);
	for (i = 1; i < vsize; i++)
		for (j = i + 1; j < vsize + 1; j++)
			if (adj[i][j] < INT_MAX) {
				e.weight = adj[i][j];
				e.v1 = i;
				e.v2 = j;
				if (e.weight != 0)
					heap.push(e);
			}
	while (edgeAccepted < vsize - 1) {
		e = heap.top();
		heap.pop();
		uset = find_set(e.v1);
		vset = find_set(e.v2);
		if (uset != vset) {
			result[edgeAccepted][0] = e.v1;
			result[edgeAccepted][1] = e.v2;
			result[edgeAccepted][2] = e.weight;
			union_set(uset, vset);
			edgeAccepted++;
		}
	}
	return edgeAccepted;
}


int main(void) {
	int x, y, w;
	scanf("%d", &vsize);

	while (~scanf("%d %d %d", &x, &y, &w)) {
		insert_edge(x, y, w);
	}

	int num = Kruskal();
	printf("%d\n", num);

	for (int i = 0; i < num; ++i) {
		printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
	}

	return 0;
}