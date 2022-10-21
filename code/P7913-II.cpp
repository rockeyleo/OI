//10.1回家后惊喜发现代码炸了……
#include <bits/stdc++.h>
using namespace std;
const int M = 500001;

struct tt{
    int in,out;
}in[M],ab[M];

struct tp{
    int time =0;
    int sum =0;
}

void read();
    n,&in[i].out);
        int flag = 1;
        for(int i=1;i<=cnt;i++){
            if(pl[i].time<=in[i].in){
                pl[i].time = in[i].out;
                pl[i].sum++;
                flag = 0;
                break;
            }
        }
        if(flag){
            pl[++cnt].time = in[i].out;
            pl[cnt].sum++;
            pl[cnt].in = in[i].in;
        }
    }
}

int ans = 0;

int main(){
    int n,m1,m2;
    cin>>n>>m1>>m2;
    read(in,pl1,m1,cnt1);
    read(ab,pl2,m2,cnt2);
    int t1,t2;
    while(true){
        if(t1==cnt1 and t2==cnt2)break;
        if(pl1[t1].sum>=pl2[t2].sum and t1<=cnt1){
            ans += push_back(pl1[t1++].sum)
        }else if(pl1[t1].sum<pl2[t2].sum and t2<=cnt2){
            ans += push_back(pl2[t2++].sum)
        }else if()
    }
    return 0;
}
