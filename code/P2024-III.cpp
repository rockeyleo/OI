#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int fa[M];
int n,k;

int find(int x){
	if(fa[x]==x)return x;
	return (fa[x]=find(fa[x]));
}

bool check1(int a,int b){
	if(find(a)==find(b+n) or find(a)==find(b+2*n)){
		return false;
	}
	return true;
}

bool check2(int a,int b){
	if(find(a)==find(b) or find(a+n)==find(b)){
		return false;
	}
	return true;
}

int fake;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n*3;i++){
		fa[i] = i;
	}
	for(int i=1;i<=k;i++){
		int opt,a,b;
		cin>>opt>>a>>b;
		if(a>n or b>n){
			fake++;
			continue;
		}
		if(opt==1){
			//a ͬ�༯�� a+n ��м��� a+2n ���Ｏ��
			if(check1(a,b)){
            	fa[find(a)] = find(b);
            	fa[find(a+n)] = find(b+n);
            	fa[find(a+2*n)] = find(b+2*n);
			}else{
				fake++;
			}
		}else{
			if(check2(a,b)){
            	fa[find(a+2*n)] = find(b);
				fa[find(a+n)] = find(b+2*n); //ע����һ�a����к�b��������ͬһ������
				fa[find(a)] = find(b+n);
			}else{
				fake++;
			}
		}
	}
	cout<<fake<<endl;
}
