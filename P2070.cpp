#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
struct nd{
    int val,opt;
}node[M*2];
int cnt = 0;
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int last = 0;
    for(int i=1;i<=n;i++){
        int tmp; char op;
        cin>>tmp>>op;
        if(op=='L'){
            tmp*=-1;
            node[++cnt]={last+tmp,1};  //1表示左界，-1表示右界
            node[++cnt]={last,-1};
        }else{
            node[++cnt]={last,1};
            node[++cnt]={last+tmp,-1};
        }
        last+=tmp;
    }
    sort(node+1,node+cnt+1,[](nd a,nd b){return a.val<b.val;});
    int now = 0;
    int ans = 0;
    for(int i=1;i<=cnt-1;i++){
        now += node[i].opt;
        if(now>=2)ans+=node[i+1].val-node[i].val;
    }
    cout<<ans<<endl;
}