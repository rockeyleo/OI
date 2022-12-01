#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1000010;
typedef long long ll;

struct Edge {int to; ll cost; };

int n, m;
vector<Edge> graph[MAXN];
int a[MAXN], b[MAXN], c[MAXN];

int next_node;

struct DijkstraNode { int pos; ll dis; };
bool operator< (DijkstraNode n1, DijkstraNode n2) {
	return n1.dis > n2.dis;
}

ll dis[MAXN];
bool vis[MAXN];
void dijkstra(int total_node) {
	priority_queue<DijkstraNode> pq;
	for (int i = 1; i <= total_node; ++i) dis[i] = LLONG_MAX;
	dis[1] = 0;
	pq.push({1, dis[1]});
	while (!pq.empty()) {
		int u = pq.top().pos;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (Edge edge : graph[u]) {
			int v = edge.to;
			if (dis[v] > dis[u]+edge.cost) {
				dis[v] = dis[u]+edge.cost;
				pq.push({v, dis[v]});
			}
		}
	}
}

void construct_edges() {
	int trans = next_node++;
	for (int i = 1; i <= n; ++i) {
		graph[i].push_back({trans, c[i]});
		graph[trans].push_back({i, c[i]});
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({v, c});
	}
	
	next_node = n+1;

	construct_edges();

	dijkstra(next_node);

	cout << dis[n] << endl;
}