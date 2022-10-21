#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	string in;
	string sout[10];
	char o[10][10];
	string word[21] = {
		"zero", "one", "two", "three", "four", "five", "six", "seven",
		"eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"
	};

	vector<int> out;
	vector<string> i;
	while (cin >> in) {
		i.push_back(in);
	}

	for (auto &x : i) {
		for (int j = 1; j <= 21; j++) {
			if (x == word[j])
				out.push_back(j);
		}
	}

	for (int x=0;x<=out.size()-1;x++) {
		sprintf(o[x],"%d",out[x]);
		sout[x] = o[x];
		if (sout[x].length()==1)
			sout[x]="0"+sout[x];
		cout<<sout[x]<<endl;
	}
}
