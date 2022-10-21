#include <bits/stdc++.h>
using namespace std;
string st[30];
string word[27] = {
		"zero", "one", "two", "three", "four", "five", "six", "seven",
		"eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
        "a","both","another","first","second","third"
};

int pd(int i){
    if(i<=20){
        return i;
    }
    switch(i){
        case 21:return 1;
        case 22:return 2;
        case 23:return 1;
        case 24:return 1;
        case 25:return 2;
        case 26:return 3;
    }
}

int main(){
    string a,ans;
    int mid[30];
    memset(mid,0,sizeof(mid));
    int cnt;
    while(a!="."){
        cin>>a;
        st[++cnt]=a;
    }
    int tmp=0;
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=26;j++){
            if(word[j]==st[i]){
                mid[++tmp]=(pow(pd(j),2));
            }
        }
    }
    for(int &ap:mid){
        ap=ap%100;
        // cout<<ap<<" ";
    }
    if(mid[1]==0){
        for(int i=2;i<=tmp;i++){
            if(mid[i]%10==mid[i] and i!=2){
                ans = ans+"0"+to_string(mid[i]);
            }else{
                ans += to_string(mid[i]);
            }
        }
    }else{
        for(int i=1;i<=tmp;i++){
            if(mid[i]%10==mid[i] and i!=1){
                ans = ans+"0"+to_string(mid[i]);
            }else{
                ans += to_string(mid[i]);
            }
        }
    }
    if(ans == ""){
        cout<<0<<endl;
    }else{
        cout<<ans<<endl;
    }
}