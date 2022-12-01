#include <bits/stdc++.h>
using namespace std;
const int N = 500000 + 5;
int T, p, to[N], ls, tot = 0, len[N], ll[N], type[N], tag = 0, lef[N];
string s;
stack<int> st;
vector<int> adj[N];
map<char, int> mp;
bool check(char c) {return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');}
int dfs(int l, int r) {
	int tt = ++tot, tmp = 0;
	type[tt] = mp[s[l]];
	if (check(s[l]) && to[l] == r) {len[tt] = r - l + 1; lef[tt] = l; return tt;}
	for (int i = to[l + 1 + (s[l] == '(')], lst = l + 1 + (s[l] == '('); i < r && i; i = to[lst]) {
		int w = dfs(lst, i);
		adj[tt].push_back(w);
		tmp += len[w];
		lst = i + 1 + (s[i] == '(');
	}
	ll[tt] = len[tt] = tmp; lef[tt] = l;
	if (s[l] == '(') len[tt] = tmp * (s[l + 1] - '0');
	return tt;
}
void print(char c, int t) {
	if (!t) cout << c;
	else if (c >= 'a' && c <= 'z') cout << (char)(c - 'a' + 'A');
	else cout << (char)(c - 'A' + 'a');
}
void getans(int u) {
	if (type[u] == 0) {
		char c = s[lef[u] + p - 1];
		print(c, tag);
		return;
	}
	if (type[u] == 1) {
		p %= ll[u];
		if (!p) p = ll[u];
	}
	if (type[u] == 2) tag ^= 1;
	if (type[u] == 3) p = len[u] - p + 1;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (p <= len[v]) {
			getans(v);
			return;
		}
		p -= len[v];
	}
}
void init() {
	tot = tag = 0;
	memset(to, 0, sizeof(to));
	memset(len, 0, sizeof(len));
	memset(ll, 0, sizeof(ll));
	memset(type, 0, sizeof(type));
	memset(lef, 0, sizeof(lef));
	for (int i = 0; i < N; ++i) adj[i].clear();
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	mp['('] = 1; mp['['] = 2; mp['{'] = 3;
	cin >> T;
	while (T--) {
		cin >> s >> p;
		ls = s.size(); s = "." + s + ".";
		init();
		int d = 0;
		for (int i = 1; i <= ls; ++i) {
			int flag = 0;
			if (st.empty() || s[i] == '(' || s[i] == '[' || s[i] == '{' || (check(s[i]) && !d)) {
				st.push(i);
				if (check(s[i]) && !d) d = 1;
			} if (s[st.top()] == '(' && s[i] == ')') flag = 1;	
			if (s[st.top()] == '[' && s[i] == ']') flag = 1;
			if (s[st.top()] == '{' && s[i] == '}') flag = 1;
			if (check(s[st.top()]) && !check(s[i + 1])) flag = 2;
			if (flag) to[st.top()] = i, st.pop();
			if (flag == 2) d = 0;
		}
		for (int i = to[1], lst = 1; i <= ls && i; i = to[lst]) {
			int w = dfs(lst, i);
			adj[0].push_back(w);
			lst = i + 1;
		}
		type[0] = 10;
		getans(0);
	}
	return 0;
}
