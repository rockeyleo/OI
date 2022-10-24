#include <bits/stdc++.h>
using namespace std;
const int M = 5005;
int s[M],g[M];
// int head[M],nxt[M],to[M],cnt;
int in[M],out[M],ans=1;
int edge[1001][1001];
// void add(int f,int t){
//     in[t]++;
//     out[f]++;
//     to[++cnt] = t;
//     nxt[cnt] = head[f];
//     head[f] = cnt;
// }

void add(int f,int t){
    edge[f][t] = 1;
    in[t]++;
    out[f]++;
}

queue<int>q;

int main(){
    // freopen("P1983_5.in","r",stdin);
    // freopen("P1983_5.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int s;
        cin>>s;
        int st,ed;
        for(int i=1;i<=n;i++){
            g[i] = 0;
        }
        for(int i=1;i<=s;i++){
            int tmp; cin>>tmp;
            if(i==1)st = tmp;
            if(i==s)ed = tmp;
            g[tmp] = 1;
        }
        for(int k=st;k<=ed;k++){
            if(!g[k]){
                for(int w=st;w<=ed;w++){
                    if(g[w])add(k,w);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0)q.push(i);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        int flag = 0;
        for(int i=1;i<=n;i++){
            if(edge[now][i]==1)
                in[i]--;
                if(in[i]==0){
                    flag = 1;
                    q.push(i);
                }
        }
        if(flag)ans++;
    }
    cout<<ans<<endl;
}