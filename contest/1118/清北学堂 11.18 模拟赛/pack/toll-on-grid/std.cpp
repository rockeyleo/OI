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

constexpr int MAXN = 100010;
constexpr int MAXK = 510;
constexpr int MAXA0 = 510;

int n, m, k, a0;
struct Pos {int x, y; };
Pos toll[MAXK];

bool operator<(const Pos &a, const Pos &b) {
	return a.x+a.y < b.x+b.y;
}

void readin() {
	cin >> n >> m >> k >> a0;
	for (int i = 1; i <= k; ++i) 
		cin >> toll[i].x >> toll[i].y;
	sort(toll+1, toll+1+k);
	toll[0].x = toll[0].y = 1;
}

// dp[i][j] 表示从第 j 个收费站到 (n,m)，中途途径 i 个其他的收费站（不包括 j）的路径数
// 为了方便写代码，我们假设第 0 个收费站位于 (1,1) 处
ll dp[MAXK][MAXK];

// 计算所有 dp[0][?] 的值
void calc_dp0() {
	for (int i = k; i >= 0; --i) {
		dp[0][i] = path_cnt(toll[i].x, toll[i].y, n, m);
		for (int j = i+1; j <= k; ++j) {
			subi(dp[0][i],
				dp[0][j]*path_cnt(toll[i].x, toll[i].y, toll[j].x, toll[j].y)%MOD );
		}
	}
}

// 计算所有 dp[!=0][?] 的值
void calc_dp_other() {
	for (int i = 1; i <= k; ++i) {
		for (int j = k; j >= 0; --j) {
			dp[i][j] = path_cnt(toll[j].x, toll[j].y, n, m);
			for (int l = j+1; l <= k; ++l)
				subi(dp[i][j],
					path_cnt(toll[j].x, toll[j].y, toll[l].x, toll[l].y)*dp[i][l]%MOD );
			for (int l = 0; l < i; ++l)
				subi(dp[i][j],
					dp[l][j]);
		}
	}
}

int main() {
	init_fact();
	readin();

	calc_dp0();

	calc_dp_other();

	ll ans = 0;
	for (int i = 0; i <= k; ++i) {
		ll money_left = max(a0 - i, 0);
		ll score = power(money_left, 4) + 3*power(money_left, 3) + power(5, money_left) + 6*money_left + 233;
		score %= MOD;
		addi(ans, score*dp[i][0]%MOD);
	}
	ll path_count = path_cnt(1, 1, n, m);
	(ans *= inv(path_count)) %= MOD;
	cout << ans << endl;

	return 0;
}