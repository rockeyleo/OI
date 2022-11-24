#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int n;
const int M = 500001;
pair<double,double> pt[M];
void solve(int t){
	double xx = 0, yy = 0, px = 0, py = 0;
	for(int i=1;i<=t;i++){
		px += pt[i].x;
		py += pt[i].y;
	}
	px /= (double)t, py /= (double)t;
	for(int i=1;i<=t;i++){
		xx+=(pt[i].x-px)*(pt[i].y-py);
		yy+=(pt[i].x-px)*(pt[i].x-px);
	}
	printf("%.4lf ",xx/yy);
	printf("%.4lf\n",py-(xx/yy)*px);
	return;
	
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
//	ios::sync_with_stdio(false);[
	cin>>n;
	for(int i=1;i<=n;i++){
		double xx,yy;
		scanf("%lf%lf",&xx,&yy);
		pt[i] = {xx,yy};
		if(i>=2){
			solve(i);
		}
	}
}
