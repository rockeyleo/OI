#include<bits/stdc++.h>
#define LL long long 
#define int long long
using namespace std;
const int MAXN = 1e6 + 10;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int N, dep[MAXN], siz[MAXN], son[MAXN], dsu[MAXN], Son, vis[MAXN], ds[MAXN];
vector<int> v[MAXN];
set<int> s;
LL AnsOut, AnsIn, ans;
void dfs(int x, int _fa) {
    siz[x] = 1;
    for(int i = 0; i < v[x].size(); i++) {
        int to = v[x][i]; if(to == _fa) continue;
        dfs(to, x);
        siz[x] += siz[to];
        if(siz[to] > siz[son[x]]) son[x] = to;
    }
}
LL calc(LL x) {
    return x * (x - 1) / 2;
}
void Clear() {
    s.clear(); AnsOut = calc(N); AnsIn = 0;
    s.insert(0); s.insert(N + 1);
}
int find(int x) {
    return dsu[x] == x ? dsu[x] : dsu[x] = find(dsu[x]);
}
void solve(int x) {
    s.insert(x);
    set<int>::iterator s1, s2, it;
    s1 = s2 = it = s.find(x);
    s1--; s2++;
    AnsOut -= calc((*s2) - (*s1) - 1);
    AnsOut += calc((*s2) - (*it) - 1) + calc((*it) - (*s1) - 1);
    vis[x] = 1;
    if(vis[x - 1]) {
        int fx = find(x - 1), fy = find(x);
        AnsIn += ds[fx] * ds[fy];
        dsu[fx] = fy;
        ds[fy] += ds[fx];
    }
    if(vis[x + 1]) {
        int fx = find(x + 1), fy = find(x);
        AnsIn += ds[fx] * ds[fy];
        dsu[fx] = fy;
        ds[fy] += ds[fx];
    }
}
void Add(int x, int fa) {
    solve(x);
    for(int i = 0; i < v[x].size(); i++) {
        int to = v[x][i];
        if(to == fa || to == Son) continue;
        Add(to, x);
    }
}
void Delet(int x, int fa) {
    vis[x] = 0; ds[x] = 1; dsu[x] = x;
    for(int i = 0; i < v[x].size(); i++) {
        int to = v[x][i];
        if(to == fa) continue;
        Delet(to, x);
    }
} 
void dfs2(int x, int fa, int opt) {
    for(int i = 0; i < v[x].size(); i++) {
        int to = v[x][i];
        if(to == fa || (to == son[x])) continue;
        dfs2(to, x, 0);
    }
    if(son[x]) dfs2(son[x], x, 1); Son = son[x];
    Add(x, fa);
    ans += calc(N) - AnsIn - AnsOut;
    if(opt == 0) Delet(x, fa), Clear(), Son = 0;
}
signed main() {
    N = read();
    for(int i = 1; i <= N - 1; i++) {
        int x = read(), y = read();
        v[x].push_back(y); v[y].push_back(x);
    }
    for(int i = 1; i <= N; i++) dsu[i] = i, ds[i] = 1;
    dep[1] = 1; dfs(1, 0);
    Clear(); 
    dfs2(1, 0, 0);
    cout << ans;
    return 0;
}
