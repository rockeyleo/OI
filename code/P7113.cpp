#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int head[M],nxt[M],to[M],cnt;
int in[M],out[M];
struct nm{
    __int128_t p,q;
}tmp,val[M];

__int128_t gcd(__int128_t m, __int128_t n){
    while (n != 0){
	  __int128_t t = m % n;
	  m = n;
	  n = t;
	}
    return m;
}

void write(__int128_t x){
    __int128_t y=10,len=1;
    while(y<=x){y*=10;len++;}
    while(len--){y/=10;putchar(x/y+48);x%=y;}
}

void gc(nm &a){
    __int128_t gd = gcd(a.p,a.q);
    a.p /= gd;
    a.q /= gd;
}

nm addd(nm a,nm b){
    gc(a);gc(b);
    __int128_t p1 = a.p, p2 = b.p;
    __int128_t q1 = a.q, q2 = b.q;
    __int128_t qa = q1*q2;
    __int128_t pa = q2*p1+p2*q1;
    tmp.p = pa, tmp.q = qa;
    gc(tmp);
    return tmp;
}

int n,m;
queue<int>q;

void add(int f,int t){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

int main(){
    freopen("P7113_4.in","r",stdin);
    freopen("P7113_4.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int d; 
        cin>>d; out[i] = d;
        for(int j=1;j<=d;j++){
            int tmp;
            cin>>tmp;
            add(i,tmp);
            in[tmp]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            val[i].p = val[i].q = 1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(int i=head[now];i;i=nxt[i]){
            in[to[i]]--;
            if(val[to[i]].p==0){
                val[to[i]]={val[now].p,val[now].q*out[now]};
            }else{
                nm tp = addd(val[to[i]],{val[now].p,val[now].q*out[now]});
                val[to[i]] = tp;
            }
            if(in[to[i]]==0){
                q.push(to[i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(out[i]==0){
            gc(val[i]);
            write(val[i].p);
            printf(" ");
            write(val[i].q);
            printf("\n");
        }
    }
}