#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

bool cmp(int a,int b){
    return(a>b); //sort整个数组的cmp返回都为true时，排序结束,此处为从大到小
}

int main(){
    //sort前闭后开，默认从小到大排序
    int n;
    int a[100];
    memset(a,0,sizeof(a));
    cin>>n;
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);

    for(int x:a){
        cout<<x<<ends;
    }
}