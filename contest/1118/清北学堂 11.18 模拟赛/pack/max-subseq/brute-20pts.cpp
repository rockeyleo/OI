#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 200010;
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

vector<int> ansl;
ll ans_weight = 0;

vector<int> selected;
void dfs(int pos) {
	if (pos == N+1) {
		ll sel_weight = calc_weight(selected);
		if (sel_weight > ans_weight) {
			ans_weight = sel_weight;
			ansl = selected;
		}
		return;
	}
	dfs(pos+1);
	selected.push_back(a[pos]);
	dfs(pos+1);
	selected.pop_back();
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i<= N; ++i)
		scanf("%d", &a[i]);
	
	dfs(1);

	printf("%lld\n", ans_weight);
	printf("%lu\n", ansl.size());
	for (int x : ansl) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}