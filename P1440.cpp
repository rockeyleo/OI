//得分80，两个点MLE
#include <bits/stdc++.h>
using namespace std;
const int M = 2000000;
int f[M][24];

int lg(int i){
    if(i==1)return 0;
    return(lg(i/2)+1);
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i][0]);
    }
    for(int j=1;(1<<j)<=m;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    cout<<0<<endl;
    int l,len;
    for(int i=1;i<=n-1;i++){
        l=max(1,i-m+1);
        len=lg(i-l+1);
        // len = lg(n-2+1);
        // int r=n;
        cout<<min(f[l][len],f[i-(1<<len)+1][len])<<endl;
    }
}

/*单调队列，可AC
#include <bits/stdc++.h>
using namespace std;
deque<pair<int,int>>dq; //<pos,val>
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n-1;i++){
        int tmp;
        scanf("%d",&tmp);
        // cin>>tmp;    //这个题用iostream还真就不行
        if(dq.empty()){
            // cout<<0<<endl;
            printf("%d\n",0);
        }
        if(!dq.empty() and dq.front().first<(i-m+1))dq.pop_front();
        while(!dq.empty() and dq.back().second>=tmp){    //千万注意危险内存访问！！！！！！！一定要判断非空！！！！！！
            dq.pop_back();
        }
        dq.push_back(make_pair(i,tmp));
        printf("%d\n",dq.front().second);
        // cout<<dq.front().second<<endl;
    }
}
*/