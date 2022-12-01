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

// dp[i] 表示从第 i 个收费站到 (n,m)，中途途不途径其他任何收费站的路径数
// 为了方便写代码，我们假设第 0 个收费站位于 (1,1) 处
ll dp[MAXK];

void calc_dp() {
	for (int i = k; i >= 0; --i) {
		dp[i] = path_cnt(toll[i].x, toll[i].y, n, m);
		for (int j = i+1; j <= k; ++j) {
			subi(dp[i],
				dp[j]*path_cnt(toll[i].x, toll[i].y, toll[j].x, toll[j].y)%MOD );
		}
	}
}

int main() {
	init_fact();
	readin();

	calc_dp();

	ll path_count = path_cnt(1, 1, n, m);
	ll ans = 0;
	// 如果一个收费站都不途径，那么我还剩一块钱，积分为 1+3+5+6+233 = 248
	ans += dp[0]*248;
	// 如果我途径 >= 1 个收费站，那么我就身无分文，积分为 1+233 = 234
	ans += (path_count-dp[0]+MOD)*234;
	ans %= MOD;
	(ans *= inv(path_count)) %= MOD;
	cout << ans << endl;

	return 0;
}