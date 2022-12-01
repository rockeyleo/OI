#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
 
unordered_map<ll,ll> mmp[123];
ll c[57],ans;
bool v[177];
char s[177];
int n,num;
 
inline ll G(char x){ return x-'A'+3;}
 
inline void update(){
    ll z=0,f=0;
    num=0; for(int i=n;i;i--) if(v[i]) f=f+G(s[i])*c[num++];
    num=0; for(int i=1;i<=n;i++) if(!v[i]) z=z+G(s[i])*c[num++];
    mmp[num][z-f*c[num]]++;
}
 
inline void calc(){
    ll z=0,f=0;
    num=0; for(int i=2*n;i>n;i--) if(v[i]) f=f+G(s[i])*c[num++];
    num=0; for(int i=n+1;i<=n*2;i++) if(!v[i]) z=z+G(s[i])*c[num++];
    ans+=mmp[n-num][f-z*c[n-num]];
}
 
void dfs1(int L){
    if(L==n){ update(); return;}
    dfs1(L+1),v[L+1]=1,dfs1(L+1),v[L+1]=0;
}
 
void dfs2(int L){
    if(L==n*2){ calc(); return;}
    dfs2(L+1),v[L+1]=1,dfs2(L+1),v[L+1]=0;
}
 
int main(){
    scanf("%s",s+1);
    n = strlen(s+1) / 2;
    c[0]=1; for(int i=1;i<=n;i++) c[i]=c[i-1]*233ll;
    dfs1(0);
    dfs2(n);
    printf("%llu\n",ans);
    return 0;
}