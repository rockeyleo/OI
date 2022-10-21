#include <iostream>
using namespace std;

int main() {
	string i, j;
	cin >> i;
	j = i[0];
	int a[26] = {1, 0};
	int c = 0;
	int maxn = 1;
	int minn = i[0];
	const int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

	for (int x = 0; x <= i.length() - 1; x++) {
		for (int j = i.length() - 1; j >= 0; j--) {
			if (i[x] > i[j] and x <= j) {
				swap(i[x], i[j]);
			}
		}
	}

	for (int x = 0; x <= i.length() - 2; x++) {
		if (i[x] == i[x + 1]) {
			a[c]++;
		} else {
			c += 1;
			a[c]++;
		}
	}


	for (int x = 0; x <= 24; x++) {
		if (a[x] > maxn) {
			maxn = a[x];
		} else if (a[x] < minn and a[x] != 0) {
			minn = a[x];
		}
	}

	for (auto x : prime) {
		if (x == maxn - minn) {
			cout << "Lucky Word\n" << maxn - minn << endl;
			return 0;
		}
	}
	cout << "No Answer\n" << 0 << endl;
}
