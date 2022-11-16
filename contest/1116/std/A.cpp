#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 50;
int sq[N];

int main() {
	int p;
	cin >> p;
	memset(sq, -1, sizeof sq);
	for (int i = 0; i < p; ++i)
		sq[1ll * i * i % p] = i;
	int mx = -1;
	for (int i = 0; i < p; ++i) {
		for (int a = 0; a < p; ++a) {
			int b = ((i - 1ll * a * a) % p + p) % p;
			if (sq[b] != -1) {
				ok = true;
				mx = max(a, mx);
				break;
			}
		}
	}
	cout << mx << '\n';
}
