#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 200005;
template <typename T>
struct SegTreeSumDelay {
  int e2;
  vector<T> nodes;
  T defv;
  vector<bool> dls;
  SegTreeSumDelay() {}

  void init(int n, T _defv) {
    defv = _defv;
    for (e2 = 1; e2 < n; e2 <<= 1);
    nodes.assign(e2 * 2, defv);
    dls.assign(e2 * 2, false);
  }

  T &geti(int i) { return nodes[e2 - 1 + i]; }
  void seti(int i, T v) { geti(i) = v; }

  void setall() {
    for (int j = e2 - 2; j >= 0; j--)
      nodes[j] = nodes[j * 2 + 1] + nodes[j * 2 + 2];
  }

  void __update(int k) {
    if (dls[k]) {
      int k0 = k * 2 + 1, k1 = k0 + 1;
      nodes[k0] = nodes[k1] = nodes[k] / 2;
      dls[k0] = dls[k1] = true;
      dls[k] = false;
    }
  }

  void set_range(int r0, int r1, T v, int k, int i0, int i1) {
    if (r1 <= i0 || i1 <= r0) return;
    if (r0 <= i0 && i1 <= r1) {
      nodes[k] = v * (i1 - i0);
      dls[k] = true;
      return;
    }

    __update(k);

    int im = (i0 + i1) / 2;
    int k0 = k * 2 + 1, k1 = k0 + 1;
    set_range(r0, r1, v, k0, i0, im);
    set_range(r0, r1, v, k1, im, i1);
    nodes[k] = nodes[k0] + nodes[k1];
  }
  void set_range(int r0, int r1, T v) { set_range(r0, r1, v, 0, 0, e2); }

  T sum_range(int r0, int r1, int k, int i0, int i1) {
    if (r1 <= i0 || i1 <= r0) return defv;
    if (r0 <= i0 && i1 <= r1) return nodes[k];

    __update(k);

    int im = (i0 + i1) / 2;
    T v0 = sum_range(r0, r1, k * 2 + 1, i0, im);
    T v1 = sum_range(r0, r1, k * 2 + 2, im, i1);
    return v0 + v1;
  }
  T sum_range(int r0, int r1) { return sum_range(r0, r1, 0, 0, e2); }
};

int as[MAX_N], uas[MAX_N];
int dpl[MAX_N], dpr[MAX_N];
SegTreeSumDelay<int> st;

int main() {
  int n, qn, k;
  scanf("%d%d%d", &n, &qn, &k);

  for (int i = 0; i < n; i++) scanf("%d", as + i);
  copy(as, as + n, uas);
  sort(uas, uas + n);
  int m = unique(uas, uas + n) - uas;

  st.init(m, 0);
  for (int i = 0; i < n; i++) {
    int uj = upper_bound(uas, uas + m, k - as[i]) - uas;
    dpl[i] = i - st.sum_range(0, uj);

    int aj = lower_bound(uas, uas + m, as[i]) - uas;
    int d = 0;
    if (uj < aj) {
      d = st.sum_range(uj, aj);
      st.set_range(uj, aj, 0);
    }

    st.set_range(aj, aj + 1, st.sum_range(aj, aj + 1) + d + 1);
  }
  //for (int i = 0; i < n; i++) printf("%d ", dpl[i]); putchar('\n');
  
  st.init(m, 0);
  for (int i = n - 1; i >= 0; i--) {
    int uj = upper_bound(uas, uas + m, k - as[i]) - uas;
    dpr[i] = (n - 1 - i) - st.sum_range(0, uj);

    int aj = lower_bound(uas, uas + m, as[i]) - uas;
    int d = 0;
    if (uj < aj) {
      d = st.sum_range(uj, aj);
      st.set_range(uj, aj, 0);
    }

    st.set_range(aj, aj + 1, st.sum_range(aj, aj + 1) + d + 1);
  }
  //for (int i = 0; i < n; i++) printf("%d ", dpr[i]); putchar('\n');

  while (qn--) {
    int s, t;
    scanf("%d%d", &s, &t);
    s--, t--;

    bool ok = (dpl[s] <= t && t <= n - 1 - dpr[s]);
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}

