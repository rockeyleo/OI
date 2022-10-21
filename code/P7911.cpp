#include <bits/stdc++.h>
using namespace std;
int srver[10010][5];
int client[10010][5];
map<string,int>mp;
int main(){
    int n;
    int cnt = 0;
    cin>>n;
    for(int i=1;i<=n;i++){
        string opt;
        cin>>opt;
        switch(opt){
            case "Client":{
                string ip;
                cin>>ip;
                int a,b,c,d,e;
                scanf("%d%*c%d%*c%d%*c%d%*c%d",&a,&b,&c,&d,&e);
                
                if(!(a>=0 and a<=255 and b>=0 and b<=255 and c>=0 and c<=255 and d>=0 and d<=65535)){
                    cout<<"ERR"<<endl;
                    break;
                }
                string tmp = to_string(a)+'.'+to_string(b)+'.'+to_string(c)+'.'+to_string(d)+':'+to_string(e);
                if(tmp != ip){
                    cout<<"ERR"<<endl;
                    break;
                }
                if(mp[tmp]==0){
                    cout<<"FAIL"<<endl;
                }else{
                    cout<<mp[tmp]<<endl;
                    mp[tmp]=-1;
                }
            }
            case "Server":{
                string ip;
                cin>>ip;
                int a,b,c,d,e;
                scanf("%d%*c%d%*c%d%*c%d%*c%d",&a,&b,&c,&d,&e);
                
                if(!(a>=0 and a<=255 and b>=0 and b<=255 and c>=0 and c<=255 and d>=0 and d<=65535)){
                    cout<<"ERR"<<endl;
                    break;
                }
                string tmp = to_string(a)+'.'+to_string(b)+'.'+to_string(c)+'.'+to_string(d)+':'+to_string(e);
                if(tmp != ip){
                    cout<<"ERR"<<endl;
                    break;
                }
                if(mp[tmp]==0){
                    cout<<"OK"<<endl;
                    mp[tmp]==n;
                }else{
                    cout<<"FAIL"<<endl;
                }
                break;
            }
        }
    }
}