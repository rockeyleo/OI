#include <bits/stdc++.h>
using namespace std;
int num[5001];
int main(){
    freopen("table.txt","w",stdout);
    for(int i=1;i<=5000;i++){
        if(i==1 or i==2){
            cout<<1<<endl;continue;
        }else if(i==3){
            cout<<"1 3"<<endl;continue;
        }
        for(int j=1;j<=i;j++){
            num[j]=j;
        }
        int cnt=i;
        while(true){
            if(cnt<=3)break;
            // cnt = i;
            int j=1;
            while(j<=cnt){
                if(num[j]!=-1 and j%2==0){
                    num[j]=-1;cnt--;
                }
                if(num[j]!=-1)j++;
            }
            int k=1;
            while(k<=cnt){
                if(num[k]!=-1 and k%3==0){
                    num[k]=-1;cnt--;
                }
                if(num[k]!=-1)k++;
            }
        }
        for(int j=1;j<=i;j++){
            if(num[j]!=-1)cout<<num[j]<<" ";
        }
        cout<<endl;
    }
}