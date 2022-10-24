#include <bits/stdc++.h>
using namespace std;
const int M = 90000000;
int s[1001],g[1001];
int head[M],nxt[M],to[M],cnt;
int in[1001],out[1001],ans=1;
int edge[1001][1001];

void add(int f,int t){
    in[t]++;
    out[f]++;
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

queue<int>q;

int main(){
    // freopen("P1983_6.in","r",stdin);
    // freopen("P1983_6.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int s;
        cin>>s;
        int st,ed;
        memset(g,0,sizeof(g));
        for(int i=1;i<=s;i++){
            int tmp; cin>>tmp;
            if(i==1)st = tmp;
            if(i==s)ed = tmp;
            g[tmp] = 1;
        }
        for(int k=st;k<=ed;k++){
            if(!g[k]){
                for(int w=st;w<=ed;w++){
                    if(g[w] and !edge[k][w]){
                        add(k,w);                    
                        edge[k][w]=1;
                    }
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
        for(int i=head[now];i;i=nxt[i]){
            int tt = to[i];
            in[tt]--;
            if(in[tt]==0){
                flag = 1;
                q.push(tt);
            }
        }
        if(flag)ans++;
    }
    cout<<ans<<endl;
}