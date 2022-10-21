#include <iostream>
#include <cstring>

using namespace std;
unsigned long long set[10000][10000];

int fd(int x,int y){
    while(1>0){
        if(x==1 or y==1 or x==y){
            set[x][y]=1;
            return 0;
        }
        if(set[x-1][y-1]==0){
            fd(x-1,y-1);
        }else if(set[x][y-1]==0){
            fd(x,y-1);
        }else{
            set[x][y]=set[x-1][y-1]+set[x][y-1];
            return 0;
        }
    }
    
}

int main(){
    memset(set,0,sizeof(set));
    int x,y;
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        fd(i,y);
        cout<<set[i][y]<<endl;
    }
    return 0;
}