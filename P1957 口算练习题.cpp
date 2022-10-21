#include <iostream>
#include <cstdio>
#include <string>
#include <basic_string.h>

using namespace std;

int main() {
	int i;
	cin >> i;
	string j[51];
	int k[51] = {0}, l[51] = {0};
	int a[51] = {0};
	for (int x = 1; x <= i; x++) {
		cin >> j[x];
		if (j[x][0] != 'a' and j[x][0] != 'b' and j[x][0] != 'c' and j[x][0] != 'd') {
			k[x] = stoi(j[x], 0, 10);
			j[x] = j[x - 1];
			cin >> l[x];
		} else {
			cin >> k[x] >> l[x];
		}
	}

	for (int x = 1; x <= i; x++) {
		switch (j[x][0]) {
			case 'a':
				a[x] = printf("%d+%d=%d\n", k[x], l[x], k[x] + l[x]);
				break;
			case 'b':
				a[x] = printf("%d-%d=%d\n", k[x], l[x], k[x] - l[x]);
				break;
			case 'c':
				a[x] = printf("%d*%d=%d\n", k[x], l[x], k[x] * l[x]);
				break;
			case 'd':
				a[x] = printf("%d/%d=%d\n", k[x], l[x], k[x] / l[x]);
				break;
		}
		cout << a[x] - 1 << endl;
	}

}