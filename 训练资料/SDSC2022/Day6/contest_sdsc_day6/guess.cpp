#include <bits/stdc++.h>
#include <time.h>
// #include <ext/pb_ds/hash_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// unordered_map<int,int>f;
// unsigned f[200000000];
// __gnu_pbds::gp_hash_table<int,int>f;
// vector<int>f(125e8);
int lg(int n){
    if(n == 1)return 0;
    return(lg(n/2)+1);
}

long long dfs(long long n){
    if(n == 1)return 0;
    // if(f[n])return f[n];
    if(n%2==0)return(dfs(n/2)+1);
    return(dfs(n*3+1)+1);
}
int main(){
    // clock_t start,stop;
    // start = clock();
    // freopen("a.in","r",stdin);
    // freopen("a.out","w+",stdout);
    int n;
    cin>>n;
    // memset(f,-1,sizeof(f));
    // cout<<f[1];
    // for(int i=0;i<=lg(n);i++){
    //     f[1<<i] = i;
    // }
    // printf("{");
    for(int i=1;i<=n;i++){
        int tmp;
        scanf("%d",&tmp);
        printf("%lld\n",dfs(tmp));
    }
    // printf("}");
    // stop = clock();
    // double endtime=(double)(stop-start)/CLOCKS_PER_SEC; 
    // std::cerr << "time: "<<endtime <<"s" <<std::endl;
    return 0;
}