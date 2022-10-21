#include <bits/stdc++.h>
using namespace std;
// #define int long long
int bucket[100001];
queue<long long>q1;
queue<long long>q2;
long long ans;

int read(){
    int f=1;char ch=getchar();int ret=0;
    while(ch<'0' or ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0' and ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return ret*f;
}

long long get(){
    long long t1,t2;
    if(q1.empty()){
        t1 = q2.front();
        q2.pop();
        return t1;
    }else if(q2.empty()){
        t1 = q1.front();
        q1.pop();
        return t1;
    }else{
        t1 = q1.front(); t2 = q2.front();
        if(t1>t2){
            q2.pop();
            return t2;
        }else{
            q1.pop();
            return t1;
        }
    }
}

signed main(){
    // freopen("P6033_8.in","r",stdin);
    // freopen("P6033_8.out","w",stdout);
    int n;
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++){
        int t = read();
        bucket[t]++;
        mx = max(mx,t);
    }
    for(int i=1;i<=mx;i++){
        for(int j=1;j<=bucket[i];j++){
            q1.push(i);
        }
    }
    for(int i=1;i<=n-1;i++){    //n组果子一定是合并n-1次
        long long t1,t2;//, t3 = M;
        // if(!q1.empty())t1 = q1.front();
        // if(!q2.empty())t2 = q2.front();
        // if(t1>t2){
        //     q2.pop();
        //     if(!q2.empty())t3 = q2.front();
        //     if(t3<t1){q2.pop();t1=t3;}
        //     else if(!q1.empty())q1.pop();
        // }else{
        //     q1.pop();
        //     if(!q1.empty())t3 = q1.front();
        //     if(t3<t2){q1.pop();t2=t3;}
        //     else if(!q2.empty())q2.pop();
        // }
        t1 = get(),t2 = get();
        ans += t1+t2;
        // cout<<q1.size()<<" "<<q2.size()<<" "<<ans<<endl;
        q2.push(t1+t2);
    }
    cout<<ans<<endl;
}