#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int>tg;
vector<pair<int,int>>opt;
// vector<int>vec;
set<int>st;
const int M = 1000005;
int d[M],sum[M];
int main(){
    ios::sync_with_stdio(false);
    // freopen("print.in","r",stdin);
    // freopen("print.out","w",stdout);
    int n;
    cin>>n;
    int last = 0;
    // d[1]=1;
    // st.insert(0);
    for(int i=1;i<=n;i++){
        int tmp;char op;
        cin>>tmp>>op;
        if(op=='L'){
            tmp*=-1;
            opt.push_back({last+tmp,last});
        }else{
            opt.push_back({last,last+tmp});
        }
        last+=tmp;
        // mp[tmp]=1;
        // vec.push_back(last);
        st.insert(last);
    }
    // sort(vec.begin(),vec.end(),[](int a,int b){return a<b;});
    int cnt=1;
    for(auto i=st.begin();i!=st.end();i++){
        tg[*i]=cnt++;
        //auto tt =st.upper_bound(*i);
        // if(tt!=--st.end()){
        //     if(i!=--tt)cnt++;
        // }
    }
    // cout<<tg[0]<<endl;
    // d[tg[0]]=1;
    for(auto a = opt.begin();a!=opt.end();a++){
        int l = tg[(*a).first], r = tg[(*a).second];
        // cout<<tg[l]<<" "<<tg[r]<<endl;
        d[l]++,d[r+1]--;
    }
    for(int i=1;i<=cnt;i++){
        d[i]+=d[i-1];
    }
    int ans =0;
    for(int i=1;i<=cnt;i++){
        sum[i]=sum[i-1]+d[i];
        // if(d[i]<=1){
        //     for(int j=i;j<=cnt;j++){
        //         if(d[j]>1){
        //             ans++;
        //             i=j;
        //             break;
        //         }
        //     }
        // }
        // cout<<d[i]<<endl;
        if(sum[i]>=2)ans++;
    }
    cout<<ans;
}