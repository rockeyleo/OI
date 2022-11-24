#include <bits/stdc++.h>
using namespace std;
const int M = 1000020;
int read(){
	int ret = 0;
	char ch = getchar();
	while(ch<'0' or ch>'9')ch=getchar();
	while(ch>='0' and ch<='9'){
		ret = ret*10+ch-'0';
		ch = getchar();
	}
	return ret;
}
int vis[M];int bnt;
vector<int>buk;
int mp[M];
int val[1001][1001];
int ans[1001][1001];
//int f[1001][1001];
int ball[M];
int mm[M];
int n,q;
int maxn;

int f(int l,int r){
	if(l==0){
		printf("f[%d,%d]=%d\n",l,r,mm[r]);
		return mm[r];
	}else{
		printf("f[%d,%d]=%d\n",l,r,max(0,mm[r]-mm[l]));
		return max(0,mm[r]-mm[l]);
	}
}

int main(){
	freopen("ex_a2.in","r",stdin);
	freopen("ex_a2.out","w",stdout);
	n = read(), q = read();
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=i;j++){
			val[i][j] = read();
			maxn = max(maxn,val[i][j]);
//			cout<<i<<" "<<j<<endl;
			if(vis[val[i][j]]==0){
				vis[val[i][j]]=1;
				buk.push_back(val[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ball[i] = read();
	}
//	cout<<1111<<endl;
	sort(ball+1,ball+1+q);
	sort(buk.begin(),buk.end());
	int k=1;
	for(int i=0;i<=(int)buk.size()-1;i++){
		int cnt = 0;
//		cout<<i<<" "<<k<<endl;
		for(int j=k;j<=q;j++){
//			cout<<j<<" "<<ball[j]<<endl;
			if(ball[j]<=buk[i]){
				k++;cnt++;
//				cout<<k<<endl;
			}else{
				break;
			}
		}
		if(i!=0)mm[buk[i]]=mm[buk[i-1]]+cnt;
		else mm[buk[i]]=cnt;
//		printf("mm[%d]=%d\n",buk[i],mm[buk[i]]);
	}


	ans[0][1] = q;
	for(int j=1;j<=n;j++){
		int minn = val[j][j];
		if(val[j][j-1]>=minn)minn = val[j-1][j-1];
		cout<<j-1<<" "<<j<<endl;
		if(j!=1)ans[j-1][j] = f(val[j-1][j-1],maxn);
		for(int i=j;i<=n-1;i++){
//   			if(i==1)continue;
   			cout<<i<<" "<<j<<endl;
   			
   			cout<<"val[i-1][j-1]="<<val[i-1][j-1]<<endl;
			if(val[i][j]<minn){
				cout<<"val[i][j]="<<val[i][j]<<endl;
				if(val[i][j-1]>=val[i][j]){
	 				val[i][j] = val[i-1][j-1];
					cout<<"val[i][j]="<<val[i][j]<<endl;
				}else{
					minn = val[i][j];
				}
				ans[i][j] = f(val[i][j-1],val[i][j]);
			}else{
				val[i][j] = minn;
				cout<<"val[i][j]="<<val[i][j]<<endl;
				if(val[i][j-1]>=val[i][j]){
					val[i][j]=val[i-1][j-1];
					cout<<"val[i][j]="<<val[i][j]<<endl;
				}
				ans[i][j] = f(val[i][j-1],val[i][j]);
			}
		}
	}
	
	for(int i=0;i<=n-1;i++){
		for(int j=1;j<=1+i;j++){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
}
