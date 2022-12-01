#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 100010;
typedef long long ll;

struct Edge {int to; ll cost; };

int n, m;
vector<Edge> graph[MAXN];
int a[MAXN], b[MAXN], c[MAXN];

void add_fly_paths() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if ((a[i]^a[j]) >= b[i])
				graph[i].push_back({j, c[i]+c[j]});
}

ll dis[MAXN];
void spfa() {
	queue<int> q;
	for (int i = 1; i <= n; ++i) dis[i] = LLONG_MAX;
	dis[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (Edge edge : graph[u]) {
			int v = edge.to;
			if (dis[v] > dis[u]+edge.cost) {
				dis[v] = dis[u]+edge.cost;
				q.push(v);
			}
		}
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
	
	add_fly_paths();
	spfa();

	cout << (dis[n] == LLONG_MAX ? -1 : dis[n]) << endl;
}