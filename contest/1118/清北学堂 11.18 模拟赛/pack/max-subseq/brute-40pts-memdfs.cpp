#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2010;
typedef long long ll;

int N;
int a[MAXN];

// 计算一个序列 $b$ 的权值
ll calc_weight(vector<int> &b) {
	ll res = 0;
	for (int i = 0; i < (int)b.size()-1; ++i)
		res += max(b[i], b[i+1]);
	return res;
}

ll mem[MAXN][MAXN*2];
bool trans[MAXN][MAXN*2];
bool vis[MAXN][MAXN*2];
ll dfs(int pos, int last_num) {
	if (pos == N+1) {
		return 0;
	}
	if (vis[pos][last_num+MAXN])
		return mem[pos][last_num+MAXN];

	ll ans1 = dfs(pos+1, last_num);
	ll ans2 = dfs(pos+1, a[pos]) + (last_num == -2002 ? 0 : max(last_num, a[pos]));
	vis[pos][last_num+MAXN] = true;
	mem[pos][last_num+MAXN] = max(ans1, ans2);
	trans[pos][last_num+MAXN] = ans1 > ans2 ? 0 : 1;
	return max(ans1, ans2);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i<= N; ++i)
		scanf("%d", &a[i]);
	
	ll ans = dfs(1, -2002);

	vector<int> ansl;
	int last_num = -2002;
	for (int pos = 1; pos <= N; ++pos) {
		bool t = trans[pos][last_num+MAXN];
		if (t) {
			ansl.push_back(a[pos]);
			last_num = a[pos];
		} else {
			
		}
	}

	printf("%lld\n", ans);
	printf("%lu\n", ansl.size());
	for (int x : ansl) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}