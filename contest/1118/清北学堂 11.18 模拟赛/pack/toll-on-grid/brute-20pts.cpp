#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int MAXN = 510;
constexpr int MAXM = 510;
constexpr int MOD = 1'000'000'007;

int power(int a, int b) {
	assert (b >= 0);
	int res = 1;
	while(b) {
		if (b&1)
			res = 1LL*res*a % MOD;
		a = 1LL*a*a%MOD;
		b >>= 1;
	}
	return res;
}

int get_score(ll money) {
	return (money*money*money*money%MOD + 3*money*money*money%MOD + power(5, money) + 6*money + 233) % MOD;
} 

int n, m, k, a0;
bool have_roll[MAXN][MAXM];

int route[MAXN+MAXM];	// 路线，总长度为 n-1+m-1，route[i] = 1 代表向上走一步，route[i] = 0 代表向下走一步
int sum_score;
int route_count;
void calc() {
	int roll_cnt = 0;
	int x = 1, y = 1;
	for (int p = 1; p <= n-1+m-1; ++p) {
		if (route[p]) ++x;
		else ++y;
		if (have_roll[x][y]) ++roll_cnt;
	}
	assert (x == n && y == m);
	(sum_score += get_score(max(0, a0-roll_cnt))) %= MOD;
	route_count += 1;
}

void dfs_route(int cur_x, int cur_y, int route_ptr) {
	if (cur_x == n && cur_y == m) {
		assert(route_ptr == n+m-1);
		calc();
		return;
	}
	if (cur_x != n) {
		route[route_ptr] = 1;
		dfs_route(cur_x+1, cur_y, route_ptr+1);
	}
	if (cur_y != m) {
		route[route_ptr] = 0;
		dfs_route(cur_x, cur_y+1, route_ptr+1);
	}
}

int main() {
	cin >> n >> m >> k >> a0;
	for (int i = 1; i <= k; ++i) {
		int x, y;
		cin >> x >> y;
		have_roll[x][y] = true;
	}

	dfs_route(1, 1, 1);

	int ans = 1LL*sum_score*power(route_count, MOD-2) % MOD;
	cout << ans << endl;
}