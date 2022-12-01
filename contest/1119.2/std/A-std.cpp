#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
using namespace std;

const int Maxn = 100000;
const LL UB = 1000000000;

LL A[Maxn];
int N;

LL eSum[Maxn], oSum[Maxn];
LL sum[Maxn];

bool lt(int x, int a, int b){
	if(b < 0 || b >= N) return true;
	if(a < 0 || a >= N) return false;
	LL d1 = abs(x - A[a]);
	LL d2 = abs(x - A[b]);
	if(d1 < d2) return true;
	if(d1 == d2) return a < b;
	return false;
}

LL calc(int r, int d){
	if(r < 0) return 0;
	if(d == 0) return eSum[r];
	else if(d == 1) return oSum[r];
	else return sum[r];
}

LL calc(int l, int r, int d){
	if(l > r) return 0;
	return calc(r, d) - calc(l - 1, d);
}

LL query(int x){
	int lb = 1, ub = N + 1;
	while(ub - lb > 1){
		int mid = (lb + ub) / 2;
		int a = mid / 2;
		int b = mid / 2;
		if(a + b < mid) a++;
		int l = N - mid;
		int r = N - a - 1;
		// take [l, r]
		if(lt(x, r + 1, l)) ub = mid;
		else lb = mid;
	}
	// lb cards: no conflict
	int a = (lb + 1) / 2;
	int d = N % 2;
	LL ans = calc(0, N - lb - 1, d) + calc(N - lb, N - a - 1, -1);
	return sum[N - 1] - ans;
}

int main(){
	int Q;
	scanf("%d%d", &N, &Q);
	for(int i = 0; i < N; ++i) scanf("%lld", A + i);
	sum[0] = A[0];
	for(int i = 1; i < N; ++i) sum[i] = sum[i - 1] + A[i];
	eSum[0] = A[0];
	for(int i = 1; i < N; ++i) eSum[i] = eSum[i - 1] + (i % 2 == 0 ? A[i] : 0);
	oSum[0] = 0;
	for(int i = 1; i < N; ++i) oSum[i] = oSum[i - 1] + (i % 2 == 1 ? A[i] : 0);
	for(int i = 0; i < Q; ++i){
		LL x;
		scanf("%lld", &x);
		LL ans = query(x);
		printf("%lld\n", ans);
	}
	return 0;
}

