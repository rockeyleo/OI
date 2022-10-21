#include <cstring>
#include <iostream>
using namespace std;
int edge[1001][1001],dis[1001][1001];
int main(){
    int n,m,from,to,value;
    cin>>n>>m;
    memset(edge,0,sizeof(edge));
    memset(dis,-1,sizeof(dis));
    for(int i=1;i<=m;i++){
        cin>>from>>to>>value;
        edge[from][to]=value;
        dis[from][to]=value;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    cout<<dis[1][7];
}