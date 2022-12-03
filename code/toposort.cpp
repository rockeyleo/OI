#include <bits/stdc++.h>
using namespace std;
int n,m;
const int M = 50010;
int head[M],nxt[M],cnt,to[M];
int in[M];
void add(int f,int t){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
    in[t]++;
}
queue<int>q;
bool bfs(){
    int tot = 0;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
            tot++;
        }
    }
    while(!q.empty()){
        int now  = q.front();
        q.pop();
        for(int i=head[now];i;i=nxt[i]){
            int tt = to[i];
            in[tt]--;
            if(in[tt]==0){
                q.push(tt);
                tot++;
            }
        }
    }
    if(tot==n){
        return true;
    }else{
        return false;
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int f,t;
        cin>>f>>t;
        add(f,t);
    }
    bfs();
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}