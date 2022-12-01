#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int MAXN = 100110;

int N, M;
char a0_s[MAXN];
int x[MAXN];

int solve(int k) {
	int p = k;
	int ans = 0;
	while (x[p] == 1) {
		x[p] = 0;
		ans += 1;
		p += 1;
	}
	x[p] = 1;
	ans += 1;
	return ans;	
}

int main() {
	scanf("%d", &N);
	scanf("%s", a0_s);
	scanf("%d", &M);

	for (int i = 0; i < N; ++i)
		x[N-1-i] = a0_s[i]-'0';
	
	for (int i = 0; i < M; ++i) {
		int k;
		scanf("%d", &k);
		int ans = solve(k);
		printf("%d\n", ans);
	}

	int final_x_len = MAXN-1;
	while (!x[final_x_len]) --final_x_len;

	for (int i = final_x_len; i >= 0; --i)
		printf("%d", x[i]);
	printf("\n");
	
	return 0;
}