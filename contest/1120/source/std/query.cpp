#include <ext/rope>
#include <iostream>
using namespace std;
using namespace __gnu_cxx;
rope<int> S;
void solve() {
    int n, q;
    cin >> n >> q;
    S.clear();
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        S.push_back(t);
    }
    int ans = 0;
    while (q--) {
        int op, l, r, x;
        cin >> op;
        if (op == 1) {
            cin >> l >> r;
            S = S.substr(0, r) + S.substr(l - 1, n - r);
        } else {
            cin >> x;
            cout << S[x - 1] << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}