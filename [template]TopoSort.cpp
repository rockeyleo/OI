#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+5;
int to[M];
int nxt[M];
int d[M];        //d用来存储d的入度
int ans[M];
int head[M];
int cnt,cnt2,n,m;
queue<int> q;
void add(int f,int t){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

void topsort(){
    for(int i=1;i<=n;i++){
        if(d[i]==0)q.push(i);
    }
    while(!q.empty()){
        int ww = q.front();
        ans[++cnt2]=ww;
        q.pop();
        for(int i = head[ww];i;i = nxt[i]){
            int now = to[i];
            d[now]--;
            if(d[now]==0){
                q.push(now);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    memset(d,0,sizeof(d));
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        d[v]++;
    }
    topsort();
    if(cnt2==n){
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
    }else{
        cout<<"-1";
    }
}