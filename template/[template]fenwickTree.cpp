#include <bits/stdc++.h>
using namespace std;
int tree[500100],n,m;

int lowbit(int x){
    return(x&(-x));
}

int query(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i)){
        ans += tree[i];
    }
    return ans;
}

void add(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)){
        tree[i]+=k;
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        add(i,tmp);
    }
    for(int i=1;i<=m;i++){
        int opt;
        cin>>opt;
        if(opt == 1){
            int x,k;
            cin>>x>>k;
            add(x,k);
            continue;
        }else if(opt == 2){
            int x,y;
            cin>>x>>y;
            cout<<(query(y)-query(x-1))<<endl;
            continue;
        }
    }
}
