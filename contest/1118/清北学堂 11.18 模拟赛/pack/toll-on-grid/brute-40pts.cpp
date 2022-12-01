#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int MOD = 1'000'000'007;
constexpr int MAXFACT = 200010;

ll addi(ll &a, ll b) {
	a = (a+b)%MOD;	// 这里是故意这样写的，因为我不想卡常，所以标程要写的稍微拉一些
	return a;
}
ll subi(ll &a, ll b) {
	a = (a-b+MOD)%MOD;
	return a;
}

ll power(ll a, int b) {
	ll res = 1;
	while(b) {
		if(b&1) res = res*a % MOD;
		a = a*a % MOD;
		b >>= 1;
	}
	return res;
}
ll inv(ll a) {
	return power(a, MOD-2);
}
ll fact[MAXFACT], fact_inv[MAXFACT];
void init_fact() {
	fact[0] = 1;
	for (int i = 1; i < MAXFACT; ++i)
		fact[i] = fact[i-1]*i % MOD;
	for (int i = 0; i < MAXFACT; ++i)
		fact_inv[i] = inv(fact[i]);
}
ll c(int n, int m) {
	if (n < m) return 0;
	return fact[n]*fact_inv[m]%MOD * fact_inv[n-m] % MOD;
}
ll path_cnt(int x1, int y1, int x2, int y2) {
	if(x1 > x2 || y1 > y2) return 0;
	return c(x2-x1+y2-y1, x2-x1);
}

constexpr int MAXN = 260;
constexpr int MAXK = 510;
constexpr int MAXA0 = 510;

int n, m, k, a0;
bool have_roll[MAXN][MAXN];

ll dp[MAXK][MAXN][MAXN];
// dp[k][i][j] 表示从 (1, 1) 到达 (i, j)，途径 k 个收费站的路径数

void get_dp() {
	dp[0][1][1] = 1;
	for (int l = 0; l <= k; ++l) {
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (l == 0 && i == 1 && j == 1) continue;
				int prev_l = have_roll[i][j] ? l-1 : l;
				if (prev_l < 0) continue;
				// 注：这么写常数较大
				dp[l][i][j] = (dp[prev_l][i-1][j] + dp[prev_l][i][j-1]) % MOD;
			}
	}
}

int main() {
	init_fact();

	cin >> n >> m >> k >> a0;
	for (int i = 1; i <= k; ++i) {
		int x, y;
		cin >> x >> y;
		have_roll[x][y] = 1;
	}

	get_dp();

	ll sum_score = 0;
	for (int i = 0; i <= k; ++i) {
		ll money_left = max(0, a0-i);
		ll score = power(money_left, 4) + 3*power(money_left, 3) + power(5, money_left) + 6*money_left + 233;
		score %= MOD;
		(sum_score += score*dp[i][n][m]) %= MOD;
		cerr << i << " " << dp[i][n][m] << endl;
	}
	int path_cnt = c(n-1+m-1, n-1);
	ll ans = sum_score*inv(path_cnt) % MOD;
	cout << ans << endl;
}