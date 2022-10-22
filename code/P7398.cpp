#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int num[51];
int tong[1001];
bool cmp(int a,int b){
    return(a>b);
}

int main(){
    memset(tong,0,sizeof(tong));
    memset(num,-1,sizeof(num));
    string in;
    cin>>in;
    int i=0,j=0,cnt=0;
    string mid;
    while(i<=in.length()-1){
        while(in[i]>='0' and in[i]<='9'){
            mid+=in[i++];
        }
        i++;
        if(mid!=""){
            tong[stoi(mid)]=1;
            mid = "";
        }
    }
    
    // if(num[0]==-1){
    //     cout<<0<<endl;
    //     return 0;
    // }
    // sort(num,num+j-1,cmp);

    // for(int i=0;i<=j-1;i++){
    //     tong[num[i]]=1;
    // }
    for(auto x:tong){
        if(x) cnt++;
    }
    cout<<cnt;
}