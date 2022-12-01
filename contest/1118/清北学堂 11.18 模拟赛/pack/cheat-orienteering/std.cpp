#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1000010;
typedef long long ll;

struct Edge {int to; ll cost; };

int n, m;
vector<Edge> graph[MAXN];
int a[MAXN], b[MAXN], c[MAXN];

struct DijkstraNode { int pos; ll dis; };
bool operator< (DijkstraNode n1, DijkstraNode n2) {
	return n1.dis > n2.dis;
}

ll dis[MAXN];
bool vis[MAXN];
int come_from[MAXN];	// 本来出题人还想让你输出路径的，但这样就不是很优雅，所以最后没让大家输出路径。
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
				come_from[v] = u;
				pq.push({v, dis[v]});
			}
		}
	}
}

int next_node = 0;
int trie[MAXN][2];	// TRIE 树。根节点为 n+1

int trie_leaf[MAXN];	// trie_left[i] 为 a[i] 对应的 Trie 树的叶子节点
void insert_number_into_trie(int index) {
	int val = a[index];
	int pos = n+1;
	for (int k = 19; k >= 0; --k) {
		int bit = val>>k&1;
		int& nxt_pos = trie[pos][bit];
		if (!nxt_pos) nxt_pos = next_node++;
		// if (!nxt_pos) {
		// 	trie[pos][bit] = next_node++;
		// 	nxt_pos = trie[pos][bit];
		// }
		pos = nxt_pos;
	}
	trie_leaf[index] = pos;
}

void construct_downward_edges() {
	for (int i = n+1; i < next_node; ++i) {
		for (int j = 0; j <= 1; ++j) {
			int target = trie[i][j];
			if (target)
				graph[i].push_back({target, 0});
		}
	}
	for (int i = 1; i <= n; ++i) {
		graph[trie_leaf[i]].push_back({i, c[i]});
	}
}

void construct_upward_edges(int st) {
	int pos = n+1;
	for (int k = 19; k >= 0; --k) {
		int b_bit = b[st]>>k&1;
		int a_bit = a[st]>>k&1;
		if (a_bit == 0 && b_bit == 0) {
			if (trie[pos][1]) {
				graph[st].push_back({trie[pos][1], c[st]});
			}
			pos = trie[pos][0];
		}
		else if (a_bit == 1 && b_bit == 0) {
			if (trie[pos][0]) {
				graph[st].push_back({trie[pos][0], c[st]});
			}
			pos = trie[pos][1];
		}
		else if (a_bit == 0 && b_bit == 1) {
			pos = trie[pos][1];
		}
		else if (a_bit == 1 && b_bit == 1) {
			pos = trie[pos][0];
		}
		if (!pos) break;
	}
	if(pos) {
		graph[st].push_back({pos, c[st]});
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
	
	next_node = n+2;
	for (int i = 1; i <= n; ++i)
		insert_number_into_trie(i);

	for (int i = 1; i <= n; ++i)
		construct_upward_edges(i);

	construct_downward_edges();

	dijkstra(next_node);

	if (dis[n] == LLONG_MAX) dis[n] = -1;
	cout << dis[n] << endl;

	if (dis[n] != -1) {
		int pos = n;
		while (pos != 1) {
			int f = come_from[pos];
			bool is_fly = f > n;
			while (f > n) f = come_from[f];
			fprintf(stderr, "%d %s %d\n", f, is_fly?"=>":"->", pos);
			pos = f;
		} 
	}
}