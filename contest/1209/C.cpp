#include <bits/stdc++.h>
using namespace std;
int edge[4][4];
int main(){
    cin>>edge[1][2]>>edge[2][3]>>edge[1][3];
    edge[2][1] = edge[1][2], edge[3][2] = edge[2][3], edge[3][1] = edge[1][3];
    cout<<min(edge[1][2],edge[1][3]+edge[3][2])<<endl;
    cout<<min(edge[2][3],edge[2][1]+edge[1][3])<<endl;
    cout<<min(edge[1][3],edge[1][2]+edge[2][3])<<endl;
}