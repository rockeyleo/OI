#include <bits/stdc++.h>
using namespace std;
int main(){
	char rmp[101];
	scanf("%s",rmp);
	reverse(rmp,rmp+strlen(rmp));
	for(int i=0;i<=(int)strlen(rmp)-1;i++){
		cout<<rmp[i]<<endl;
	}
}
