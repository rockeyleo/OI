#include <iostream>
using namespace std;

int main() {
	int i;
	cin >> i;
	getchar();
	string a[i - 1];
	for (auto &x : a) {
		getline(cin, x);
		getchar();
	}

}