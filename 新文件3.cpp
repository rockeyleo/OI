#include <iostream>
#include <cstdio>
using namespace std;

int sum(int a) {
	if (a == 1)
		return 1;
	else
		return a + sum(a - 1);
}

int main() {
	cout << sum(100);
	return 0;
}
