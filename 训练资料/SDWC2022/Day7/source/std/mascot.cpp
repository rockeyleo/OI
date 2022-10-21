#include <bits/stdc++.h>
#define R register
#define mp make_pair
#define ll long long
#define pii pair<int, int>
using namespace std;
const int N = (1 << 20) + 1000, inf = 1e9 + 1;

int n, a[N], num;

template <class T>
inline void read(T &x) {
	x = 0;
	char ch = getchar(), w = 0;
	while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x = w ? -x : x;
	return;
}

int main() {
	freopen("mascot.in", "r", stdin);
	freopen("mascot.out", "w", stdout);
	read(n);
	for (R int i = 1; i <= n; ++i) {
		read(a[i]);
		if (a[i] == -1) num = n - i;
	}
	int tmp = n >> 1, tl = n;
	ll ans = 0;
	while (num > 0) {
		int pos = 0, minV = inf;
		for (R int i = tl; i <= n; ++i)
			if (a[i] <= minV) minV = a[i], pos = i;
		ans += minV, a[pos] = inf + 1;
		tl -= tmp, num -= tmp, tmp >>= 1;
	}
	cout << ans << endl;
	return 0;
}