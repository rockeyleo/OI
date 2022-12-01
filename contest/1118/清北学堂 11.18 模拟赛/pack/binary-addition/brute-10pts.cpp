#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int MAXN = 100010;

int popcount(ll x) {
	int res = 0;
	while (x) {
		res += x&1;
		x >>= 1;
	}
	return res;
}

ll binary_to_int(char* s) {
	int n = strlen(s);
	ll res = 0;
	for (int i = 0; i < n; ++i)
		res = res*2 + s[i] - '0';
	return res;
}

void int_to_binary(ll x, char* res) {
	stack<char> st;
	while (x) {
		st.push((x&1) + '0');
		x >>= 1;
	}
	int p = 0;
	while (!st.empty()) {
		res[p] = st.top();
		st.pop();
		++p;
	}
	res[p] = '\0';
}

int N, M;
char a0_s[MAXN];
char final_x[MAXN+20];

int main() {
	scanf("%d", &N);
	scanf("%s", a0_s);
	scanf("%d", &M);

	ll x;
	x = binary_to_int(a0_s);
	int one_cnt = popcount(x);
	
	for (int i = 0; i < M; ++i) {
		int k;
		scanf("%d", &k);
		ll t = 1 << k;
		x += t;
		int new_one_cnt = popcount(x);
		int ans = 0;
		if (new_one_cnt > one_cnt) ans = 1;
		else if (new_one_cnt == one_cnt) ans = 2;
		else ans = abs(new_one_cnt - one_cnt) + 2;
		printf("%d\n", ans);
		one_cnt = new_one_cnt;
	}
	
	int_to_binary(x, final_x);
	printf("%s\n", final_x);
}