#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
bool pd(char ip[],int a,int b,int c,int d,int e){
    char tmp[101];
    // cout<<ip<<endl;
    sprintf(tmp,"%d.%d.%d.%d:%d",a,b,c,d,e);
    if(strcmp(tmp,ip))return false;
    if(!(a>=0 and a<=255 and b>=0 and b<=255 and c>=0 and c<=255 and d>=0 and d<=255 and e>=0 and e<=65535))return false;
    return true;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string opt;
        char ip[101];
        int a,b,c,d,e;
        cin>>opt>>ip;
        sscanf(ip,"%d.%d.%d.%d:%d",&a,&b,&c,&d,&e);
        string cc = to_string(a)+"."+to_string(b)+'.'+to_string(c)+'.'+to_string(d)+':'+to_string(e);
        if(!pd(ip,a,b,c,d,e)){
            cout<<"ERR"<<endl;
            continue;
        }
        // cout<<ip<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
        if(opt == "Server"){
            if(!mp[cc]){
                cout<<"OK"<<endl;
                mp[cc] = i;
                continue;
            }else{
                cout<<"FAIL"<<endl;
                continue;
            }
        }else if(opt == "Client"){
            if(mp[cc]<=0){
                cout<<"FAIL"<<endl;
                continue;
            }else{
                cout<<mp[cc]<<endl;
                // mp[cc] = -1;
                continue;
            }
        }
    }
}