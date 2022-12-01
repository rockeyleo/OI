#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 200010;
typedef long long ll;

int N;
int a[MAXN];

vector<int> ans;

// 计算一个序列 $b$ 的权值
int calc_weight(vector<int> &b) {
	ll res = 0;
	for (int i = 0; i < (int)b.size()-1; ++i)
		res += max(b[i], b[i+1]);
	return res;
}

void solve() {
	bool is_all_neg = true;	// 是否全是负数
	for (int i = 1; i <= N; ++i)
		is_all_neg &= a[i] < 0;
	if (is_all_neg) {
		ans.clear();
		return;
	}

	// 上一个 >= 0 的数的下标
	int last_positive_index = -1;
	// 两个 >= 0 的数字之间的最大的负数
	int max_nega_num = INT_MIN;
	for (int i = 1; i <= N; ++i) {
		if (a[i] >= 0) {
			if (max_nega_num != INT_MIN)
				ans.push_back(max_nega_num);
			ans.push_back(a[i]);
			max_nega_num = INT_MIN;
		} else {
			max_nega_num = max(max_nega_num, a[i]);
		}
	}
	if (max_nega_num != INT_MIN)
		ans.push_back(max_nega_num);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i<= N; ++i)
		scanf("%d", &a[i]);
	
	solve();

	int weight = calc_weight(ans);

	printf("%d\n", weight);
	printf("%lu\n", ans.size());
	for (int x : ans) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}