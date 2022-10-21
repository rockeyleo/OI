#include <bits/stdc++.h>
using namespace std;
int num[500001],cnt;
// int qu[500001];
struct node{
    int val;
    friend bool operator<(node a,node b){return a.val>b.val;}
}tmp;
priority_queue<node>qu;
map<int,int>rfs;
map<int,int>vis;
int q,n;long long a;
int nn =0;
void bfs(int a){
    int j=0, k=0;
    tmp.val = a; qu.push(tmp);
    rfs[a]=1;
    while(j<=k){
        if(cnt>3000)return;
        int now = qu.top().val;qu.pop();
        cout<<now<<endl;
        // if(vis[now])continue;
        if(rfs[now]==-1)continue;
        if((++cnt)%q==0){
            rfs[now]=-1;
            continue;
        }
        if(rfs[now]==1){
            vis[now]=1;
            num[++nn]=now;cnt++;
            for(int i=1;i<=3;i++){
                switch(i){
                    case 1:{
                        tmp.val = 2*now+1; qu.push(tmp);
                        // qu[++k] = 2*now+1;
                    }
                    case 2:{
                        tmp.val = 3*now+1; qu.push(tmp);
                        // qu[++k] = 3*now+1;
                    }
                    case 3:{
                        tmp.val = 5*now-1; qu.push(tmp);
                        // qu[++k] = (5*now-1);
                    }
                }
            }
        }else{
            rfs[now]=1;
        }
        // cout<<cnt<<" "<<num[cnt]<<endl;
    }
}

int main(){
    cin>>a>>q>>n;
    bfs(a);
    // cout<<num[2]<<endl;
    for(int i=1;i<=n;i++){
        int w;
        cin>>w;
        cout<<num[w]<<endl;
    }
}