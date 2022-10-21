#include <bits/stdc++.h>
using namespace std;
int nxt[500100];
int main(){
    string a,b;
    a+="0",b+="0";
    string t1,t2;
    cin>>t1>>t2;
    a+=t1,b+=t2;
    int j = 0;

    for(int i=2;i<=b.length()-1;i++){
        while(j!=0 and b[j+1]!=b[i]){
            j = nxt[j];
        }
        if(b[j+1]==b[i]){
            j++;
        }
        nxt[i] = j;
    }

    j=0;
    for(int i=1;i<=a.length()-1;i++){
        while(j!=0 and a[i]!=b[j+1])j = nxt[j];
        if(a[i]==b[j+1])j++;
        if(j==b.length()-1){
            cout<<i-(b.length()-1)+1<<endl;
            j = nxt[j];
        }
    }

    for(int i=1;i<=b.length()-1;i++){
        cout<<nxt[i]<<" ";
    }
}