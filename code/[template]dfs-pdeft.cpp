#include <bits/stdc++.h>
using namespace std;
bool G[10001][10001];
int color[10001];
bool flag; //能判断不合法的地方应该不止一个，所以用flag记录
int m,n,ans,tot;

void bfs(int s){
    queue<int>q;
    int a1=0,a2=0;
    color[s] = 1;
    q.push(s);
    while(q.empty()){
        int now = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(G[now][i]){
                if(color[i] == -1){
                    color[i] = !color[now];
                    q.push(i);
                }else if(color[i] == color[now]){
                    flag =false;
                    return;
                }
            }
        }
    }
}

int main(){
    cin>>n>>m; //以无向无权图为例（不需要权，可用二维数组存图）
    for(int i=1;i<=m;i++){
        int f,t;
        cin>>f>>t;
        G[f][t] = true;
        G[t][f] = true;
    }
    memset(color,-1,sizeof(color));
    for(int i=1;i<=n;i++){
        if(color[i]==-1)bfs(i); //要考虑多个联通块的情况所以要挨个判断，保证联通的话跑一遍即可
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
}