#include <bits/stdc++.h>
using namespace std;
int s[128][128];    //s[x][y]
int num[128][128];
int main(){
    int n, ans = -0x3f3f3f3f;
    cin>>n;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            cin>>num[i][j];
            if(j == 1){
                s[i][j]=s[i-1][j]+num[i][j];
            }else if(i == 1){
                s[i][j]=s[i][j-1]+num[i][j];
            }else{
            s[i][j]=num[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            }
        }
    }
    for(int j=1;j<=n;j++){  //查询(i,j)为左上角，(x,y)为右下角的矩阵的区间和
        for(int i=1;i<=n;i++){
            for(int y = j;y<=n;y++){
                for(int x=i;x<=n;x++){
                    ans = max(ans,s[x][y]-s[i-1][y]-s[x][j-1]+s[i-1][j-1]);
                }
            }
        }
    }
    cout<<ans<<endl;
}