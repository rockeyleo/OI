#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int n;
const int M = 500001;
double px[M],py[M],xx[M],yy[M];
pair<double,double> pt[M];
void solve(int t){
	px[t] = (pt[t].x/t)+px[t-1]*(t-1)/t;
	py[t] = (pt[t].y/t)+py[t-1]*(t-1)/t;
	xx[t] = xx[t-1]+(pt[t].x-px[t])*(pt[t].y-py[t]);
	yy[t] = yy[t-1]+(pt[t].x-px[t])*(pt[t].x-px[t]);
	printf("%.4lf ",xx[t]/yy[t]);
	printf("%.4lf\n",py[t]-(xx[t]/yy[t])*px[t]);	
	return;
	
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
//	ios::sync_with_stdio(false);[
	cin>>n;
	for(int i=1;i<=n;i++){
		double tx,ty;
		scanf("%lf%lf",&tx,&ty);
		pt[i] = {tx,ty};
		if(i==1){
			px[i] = tx, py[i] = ty;
			xx[i] = (double)0;
			yy[i] = (double)0;
		}
		if(i>=2){
			solve(i);
		}
	}
}
