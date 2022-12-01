#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 200010;
typedef long long ll;

int N;
int a[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &a[i]);
	
	ll sum = 0;
	for (int i = 1; i <= N-1; ++i)
		sum += max(a[i], a[i+1]);
	
	printf("%lld\n", sum);
	printf("%d\n", N);
	for (int i = 1; i <= N; ++i)
		printf("%d ", a[i]);
	printf("\n");
}