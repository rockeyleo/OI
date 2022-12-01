#include <bits/stdc++.h>

#define ll long long

using namespace std ;
 
const int M = 22 ;
const int N = 400100 ;
const int V = 2000010 ;

int n, k, d ;
int sum[N] ;
int buc[V] ; 
int base[N] ;
ll f[2][N] ;

ll ans ; 
int L, R ; 

void add(int x){
	ans += buc[sum[x] ^ d] ; 
	buc[sum[x]] ++ ;
}
void del(int x){
	buc[sum[x]] -- ; 
	ans -= buc[sum[x] ^ d] ;
}
ll work(int l, int r){
	while (L > l) L --, add(L) ;
	while (L < l) del(L), L ++ ;
	while (R < r) R ++, add(R) ;
	while (R > r) del(R), R -- ;
	return ans ; 
}
void solve(int l, int r, int ql, int qr, int g){
	if (l > r) return ;
	int mid = (l + r) >> 1 ; 
	int pos = ql, t = min(qr, mid) ;
	for (int i = ql ; i <= t ; ++ i){
		ll val = work(i, mid) ;
//		assert(val == vv(i + 1, mid)) ;
//		cout << vv(i + 1, mid) << " " << val << endl ;
		if (f[g ^ 1][i] + val <= f[g][mid])
			f[g][mid] = f[g ^ 1][i] + val, pos = i ;
	}
	solve(l, mid - 1, ql, pos, g) ;
	solve(mid + 1, r, pos, qr, g) ;
}
int main(){
	cin >> n >> k >> d ;  
	memset(f, 63, sizeof(f)) ;
	for (int i = 1 ; i <= n ; ++ i){
		scanf("%d", &base[i]) ;
		sum[i] = sum[i - 1] ^ base[i] ;
	}
	f[0][0] = 0 ; L = 1, R = 0 ; 
	for (int d = 1, i = 1 ; i <= k ; d ^= 1, ++ i){ 
		memset(f[d], 0x3f3f3f3f, sizeof(f[d])) ; 
		solve(1, n, 0, n, d) ;
//		for (int j = 1 ; j <= n ; ++ j)
//			printf("%d%c", f[d][j], " \n"[j == n]) ; 
	}
	cout << f[k & 1][n] ;
}
