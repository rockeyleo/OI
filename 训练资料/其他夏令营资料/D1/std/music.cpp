#include<bits/stdc++.h>
using namespace std;
int main() {
//	freopen("user_out","w",stdout);
	int now=0;
	for(int i=0;i<12;i++) {
		printf("%d%c",now,i==11?'\n':' ');
		now=(now+7)%12;
	}
}
