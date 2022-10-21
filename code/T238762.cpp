#include <bits/stdc++.h>
using namespace std;
map <int,vector<int>> mp;
int vis[5000100];
int read(){
    int f=1;char ch=getchar();int ret=0;
    while(ch<'0' or ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0' and ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return ret*f;
}
int n,q,x,k;

int ans;
void dfs(vector<int> tp,int from,int cnt){
    vis[from]=1;
    if(cnt==k){
        ans = from;
        return;
    }
    if(ans!=-1)return;
    for(auto a = tp.begin();a!=tp.end();a++){
        int now = *a;
        if(!vis[now]){
            // cout<<now<<"<-"<<from<<endl;
            dfs(mp[now],now,cnt+1);
        }
    }
    return;
}

int main(){
    cin>>n>>q;
    for(int i=1;i<=n-1;i++){
        int u,v;
        u = read();
        v = read();
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    for(int i=1;i<=q;i++){
        memset(vis,0,sizeof(vis));
        x = read();
        k = read();
        vector<int>tp = mp[x];
        ans = -1;
        dfs(tp,x,0);
        printf("%d\n",ans);
    }
}