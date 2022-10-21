#include <bits/stdc++.h>
using namespace std;
struct node{
    int from,to;
}G[20002];
// int G[5000][5000];0
int color[10001];
bool flag = true; //能判断不合法的地方应该不止一个，所以用flag记录
int m,n,ans,tot,cnt;

void bfs(int s){
    queue<int>q;
    int a1=0,a2=0;
    color[s] = 1;
    // cout<<s<<":"<<color[s]<<endl;
    a1++; //先入队的
    q.push(s);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=1;i<=2*m;i++){
            if(now == G[i].from){
                int nn = G[i].to;
                if(color[nn] == -1){
                    // cout<<0<<endl;
                    color[nn] = color[now]==1?0:1;
                    // cout<<nn<<":"<<color[nn]<<endl;
                    if(color[nn]){
                        a1++;
                        // cout<<1<<endl;
                    }else{
                        a2++;
                        // cout<<2<<endl;
                    }
                    q.push(nn);
                }else if(color[nn] == color[now]){
                    flag = false;
                    return;
                }
            }
        }
    }
    // if(a1 == 0 or a2 == 0){
    //     ans = 1;return;
    // }
    ans = min(a1,a2);
    // cout<<a1<<" "<<a2<<" "<<ans<<endl;
}

int main(){
    cin>>n>>m; //以无向无权图为例（不需要权，可用二维数组存图）
    memset(G,0,sizeof(G));
    for(int i=1;i<=m;i++){
        int f,t;
        cin>>f>>t;
        G[++cnt].to = t;
        G[cnt].from = f;
        G[++cnt].to = f;
        G[cnt].from = t;    //加！边！操！作！写！两！遍！
    }
    memset(color,-1,sizeof(color));
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            // cout<<i<<" "<<color[4]<<" ";
            bfs(i);
            // if(!flag)cout<<1<<endl;
            // else cout<<0<<endl;
            tot += ans;
        } //要考虑多个联通块的情况所以要挨个判断，保证联通的话跑一遍即可
    }
    if(flag){
        // for(int i=1;i<=n;i++){
        //     cout<<i<<":"<<color[i]<<endl;
        // }
        cout<<tot<<endl;
    }else{
        // cout<<tot<<endl;
        cout<<"Impossible"<<endl;
    }
}