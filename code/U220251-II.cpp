#include <bits/stdc++.h>
using namespace std;
int num[500001],cnt;
int qu[500001];
map<int,int>rfs;
int q,n;long long a;
int nn =0;
void bfs(int a){
    int j=0, k=0;
    qu[0]=a;
    while(j<=k){
        if(cnt>3000)return;
        int now = qu[j++];
        if(rfs[now]==-1)continue;
        // cout<<now<<endl;
        if((++cnt)%q==0){
            // num[cnt]=now;
            rfs[now]=-1;
            continue;
        }
        if(rfs[now]==1){
            // vis[now]=1;
            rfs[now]=-1;
            num[++nn]=now;cnt++;
            for(int i=1;i<=3;i++){
                switch(i){
                    case 1:{
                        // tmp.val = 2*now+1; qu.push(tmp);
                        qu[++k] = 2*now+1;
                        rfs[now]=1;
                    }
                    case 2:{
                        // tmp.val = 3*now+1; qu.push(tmp);
                        qu[++k] = 3*now+1;
                    }
                    case 3:{
                        // tmp.val = 5*now-1; qu.push(tmp);
                        qu[++k] = (5*now-1);
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