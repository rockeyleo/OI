#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void m(int a,int h[]){
    int u=0;
    int i=0;

    do{
        if(a&1)//按位与是右对齐的，此时只取a(二进制)的最右位
            h[++u]=i;
        a>>=1;
        i++;
    }while(a);
}


int main(){
    int a;
    int out=0;
    int h[50];
    memset(h,-1,sizeof(h));
    cin>>a;
    m(a,h);
    
    
    for(int i=49;i>=0;i--){
        if(h[i]!=-1){
            cout<<h[i]<<endl;
        }
    }

}