#include <bits/stdc++.h>
using namespace std;
int len = 6;
int num[505] = {0,1,2,3,4,5,6};
void del(int x){
	memcpy(num+x,num+x+1,(len-x)*sizeof(num[0]));
	len--;
	for(int i=1;i<=len;i++){
		cout<<num[i]<<" ";
	}
}

void back(int x,int k){
	memcpy(num+x+1,num+x,(len-x+1)*sizeof(num[0]));
	num[x] = k;
	len++;
	for(int i=1;i<=len;i++){
		cout<<num[i]<<" ";
	}
}

int read(){
	int ret = 0; char ch = getchar();
	while(ch<'0' or ch>'9'){ch = getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0'; ch = getchar();}
	return ret;
}

int main(){
	int n = read();
	cout<<n<<endl;
}
