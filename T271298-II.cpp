#include <bits/stdc++.h>
using namespace std;

int read(){
    int f=1;char ch=getchar();int ret=0;
    while(ch<'0' or ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0' and ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return ret*f;
}

unsigned long long pre[1000001];

int main(){
    int t;
    cin>>t;
    int cnt = 0;
    int ct = 1;
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=i;j++){
            string tmp = to_string(i);
            for(int k=0;k<=tmp.size()-1;k++){
                pre[ct]=pre[ct-1]+tmp[k]-'0';
                ct++;
                cnt++;
            }
            if(cnt>=1000000)break;
        }
        if(cnt>=1000000)break;
    }
    for(int i=1;i<=t;i++){
        unsigned long long ans = 0;
        int l,r;
        l = read(); r = read();
        cout<<pre[r]-pre[l-1]<<endl;
    }
}