#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int set[100][100][100];

int w(int a,int b,int c){
    if(set[a][b][c]!=0)
        return(set[a][b][c]);
    if(a<=0 or b<= 0 or c<=0){
        set[a][b][c]=1;return 1;
    }else if(a>20 or b>20 or c>20){
        set[a][b][c]=w(20,20,20);return(set[a][b][c]);
    }else if(a<b and b<c){
        return(w(a,b,c-1)+w(a-1,b-1,c-1)-w(a,b-1,c));
    }else{
        return(w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1));
    }
}

int main(){
    memset(set,0,sizeof(set));
    int a,b,c;
    cin>>a>>b>>c;
    int ans = w(a,b,c);
    printf("w(a, b, c) = %d",ans);
}