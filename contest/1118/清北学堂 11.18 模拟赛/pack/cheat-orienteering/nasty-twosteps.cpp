#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1000010;
typedef long long ll;

struct Edge {int to; ll cost; };

int n, m;
vector<Edge> graph[MAXN];
int a[MAXN], b[MAXN], c[MAXN];

ll mid_dis[MAXN];
ll solve() {
	for (int i = 1; i <= n; ++i) {
		mid_dis[i] = 10000000000LL;
		for (auto [v, c] : graph[i])
			if (v == n) 
				mid_dis[i] = min(mid_dis[i], c);
		if ((a[i]^a[n]) >= b[i])
			mid_dis[i] = min(mid_dis[i], (ll)c[i]+c[n]);
	}
	ll ans = mid_dis[1];
	for (int mid = 2; mid <= n; ++mid) {
		if ((a[1]^a[mid]) >= b[1])
			ans = min(ans, mid_dis[mid]+c[1]+c[mid]);
	}
	for (auto [mid, c] : graph[1])
		ans = min(ans, (ll)mid_dis[mid] + c);
	return ans;
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
	
	ll ans = solve();
	cout << ans << endl;
}