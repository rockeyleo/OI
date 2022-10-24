#include <bits/stdc++.h>
using namespace std;
const int M = 7000005;
int r[M];
int gre[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int gre2[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
pair<int,int>date[M];
int yy[M];
bool grun(int year){
    if(year%400==0)return true;
    if(year%100!=0 and year%4==0)return true;
    return false;
}

bool rrun(int year){
    if(year%4==0)return true;
    return false;
}

int main(){
    yy[0]=-4713;
    // freopen("P7075_2.in","r",stdin);
    // freopen("P7075_2u.out","w",stdout);
    int q;
    cin>>q;
    int cnt=0;
    for(int y=-4713;y<1582;y++){
        if(y==0)continue;
        if(y<=0 and rrun(y+1)){
            for(int m=1;m<=12;m++){
                for(int d=1;d<=gre[m];d++){
                    date[cnt++] = {m,d}; yy[cnt]=y;
                // cout<<m<<" "<<d<<endl;
                }
            }
        }else if(y>0 and rrun(y)){
            for(int m=1;m<=12;m++){
                for(int d=1;d<=gre[m];d++){
                    date[cnt++] = {m,d}; yy[cnt]=y;
                // cout<<m<<" "<<d<<endl;
                }
            }
        }else{
            for(int m=1;m<=12;m++){
                for(int d=1;d<=gre2[m];d++){
                    date[cnt++] = {m,d}; yy[cnt]=y;
                // cout<<m<<" "<<d<<endl;
                }
            }
        }
    }
    // cout<<date[10].first<<" "<<date[10].second<<endl;
    for(int i=1;i<=q;i++){
        int r;
        scanf("%d",&r);
        if(yy[r]<0){
            printf("%d %d %d BC\n",date[r].second,date[r].first,-yy[r]);
        }else{
            printf("%d %d %d\n",date[r].second,date[r].first,yy[r]);
        }
    }
}