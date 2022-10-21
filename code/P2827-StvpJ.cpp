#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m, q, u, v, t;
    cin >> n >> m >> q >> u >> v >> t;
    int siz[3] = { n + 1, m + 1, m + 1 };
    int *ptr_b[3], *ptr_e[3];
    for (int i = 0; i < 3; ++i)
        memset(ptr_b[i] = ptr_e[i] = new int[siz[i]], 0xcf, sizeof(int) * siz[i]);
    for (int i = 0; i < n; ++i)
        cin >> *(ptr_e[0]++);
    sort(ptr_b[0], ptr_e[0], greater<int>());
    int *answer = new int[n + m];
    for (int cur = 0; cur < m; ++cur) {
        int k = 0;
        for (int i = 1; i < 3; ++i)
            if (*ptr_b[k] < *ptr_b[i])
                k = i;
        answer[cur] = cur * q + *(ptr_b[k]++);
        int a = (long long)answer[cur] * u / v;
        int b = (long long)answer[cur] - a;
        *(ptr_e[1]++) = a - (cur + 1) * q;
        *(ptr_e[2]++) = b - (cur + 1) * q;
    }
    for (int i = t - 1; i < m; i += t)
        cout << answer[i] << " ";
    cout << endl;
    for (int cur = 0; cur < n + m; ++cur) {
        int k = 0;
        for (int i = 1; i < 3; ++i)
            if (*ptr_b[k] < *ptr_b[i])
                k = i;
        answer[cur] = m * q + *(ptr_b[k]++);
    }
    for (int i = t - 1; i < n + m; i += t)
        cout << answer[i] << " ";
    cout << endl;
    return 0;
}