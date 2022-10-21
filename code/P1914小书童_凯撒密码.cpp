#include <iostream>
using namespace std;

int main() {
	string s;
	int n;
	cin >> n >> s;
	for (auto &x : s) {
		if (x + n > 122) {
			x = (x + n) - 26;
		} else {
			x += n;
		}
	}
	cout << s << endl;
}