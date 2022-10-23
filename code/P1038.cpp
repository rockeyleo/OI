#include <bits/stdc++.h>
using namespace std;
const int M = 50010;
int head[M],nxt[M],to[M],val[M],cnt;
int u[M],c[M],in[M],out[M];  //入度和出度
int n,p;
queue<int> q;

void add(int f,int t,int v){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
    val[cnt] = v;
}


int main(){
    // freopen("P1038_2.in","r",stdin);
    ios::sync_with_stdio(false);
    int n,p;
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>u[i];
    }
    for(int i=1;i<=p;i++){
        int f,t,v;
        cin>>f>>t>>v;
        out[f]++; in[t]++;
        add(f,t,v);
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0)q.push(i);
    }
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(int i=head[now];i;i=nxt[i]){
            if(c[now]>0){
                c[to[i]]+=val[i]*c[now];
            }
            in[to[i]]--;
            if(in[to[i]]==0){
                c[to[i]]-=u[to[i]];
                q.push(to[i]);
            }
        }
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
        if(out[i]==0){
            sum+=c[i];
        }
    }
    if(sum==0){cout<<"NULL"<<endl;}
    else{
        for(int i=1;i<=n;i++){
        if(out[i]==0 and c[i]>0){
            cout<<i<<" "<<c[i]<<endl;
        }
    }
    }
    
}