#incldue <bits.stdc++.h>
using namespace std;
const int MAX = 1e5;
int dp[MAX][MAX];   //dp[i][j]用于保存将i个物品放入空间为j的背包的最大价值
int val[MAX],cost[MAX];
int main(){
    int n;
    cin>>n;
    dp[0][0]=0; //唯一合法的初始状态，即0个物品放到容量为0的背包中，最大价值为0
    for(int i=1;i<=n;i++){
        cin>>val[i]>>cost[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[][]
        }
    }
}