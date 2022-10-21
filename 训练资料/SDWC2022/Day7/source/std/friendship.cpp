#include <bits/stdc++.h>
#define R register
#define mp make_pair
#define ll long long
#define pii pair<int, int>
using namespace std;
const int mod = 998244353, N = 310000;

int n, p, k;
map<int, int> app;

inline int addMod(int a, int b) {
	return (a += b) >= mod ? a - mod : a;
}

inline ll quickpow(ll base, ll pw) {
	ll ret = 1;
	while (pw) {
		if (pw & 1) ret = ret * base % mod;
		base = base * base % mod, pw >>= 1;
	}
	return ret;
}

template <class T>
inline void read(T &x) {
	x = 0;
	char ch = getchar(), w = 0;
	while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x = w ? -x : x;
	return;
}

inline ll comb(ll x) {
	return x * (x - 1) / 2 % p;
}

int main() {
	freopen("friendship.in", "r", stdin);
	freopen("friendship.out", "w", stdout);
	ll x, ans = 0;
	read(n), read(p), read(k);
	for (R int i = 1; i <= n; ++i)
		read(x), ++app[(x * x % p * x % p - k + p) * x % p];
	for (auto &v : app) ans += comb(v.second);
	cout << ans << endl;
	return 0;
}