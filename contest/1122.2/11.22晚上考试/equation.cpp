#include <bits/stdc++.h>

inline long long sum(long long i) {
  long long ans = 0;
  for (long long dk = 1; dk*dk <= i; dk++) {
    if (dk&1) {
      ans += i / dk - i/(2*dk) - (dk-1)/2;
    } else {
      ans += i / (2*dk) - (dk-1)/2;
    }
  }
  return ans;
}
 
long long L, R;
int main() {
  freopen("equation.in","r",stdin);
  freopen("equation.out","w",stdout);
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld %lld", &L, &R);
    long long ans = sum(R) - sum(L-1);
    printf("%lld\n", ans);
  }
  return 0;
}