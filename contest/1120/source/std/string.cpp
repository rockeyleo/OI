#include <bits/stdc++.h>
using namespace std;
char s[10005];
double ans=0.0;
int n;
double solve(){
    for (int i=0;i<n;i++) { //i means the middle point of the substring
        double now=1.0;
        int lx=i-1,rx=i+1;
        while (lx>=0&&rx<n)
        {
            if (s[lx]=='?'&&s[rx]=='?') now=now*1.0/26.0;
            else if (s[lx]!='?'&&s[rx]!='?'&&s[lx]==s[rx]) now=now*1.0;
            else if (s[lx]!='?'&&s[rx]!='?') now=0.0;
            else now=now*1.0/26.0;
            ans+=now;
            --lx;++rx;
        }
        now=1.0,lx=i,rx=i+1;
        while (lx>=0&&rx<n)
        {
            if (s[lx]=='?'&&s[rx]=='?') now=now*1.0/26.0;
            else if (s[lx]!='?'&&s[rx]!='?'&&s[lx]==s[rx]) now=now*1.0;
            else if (s[lx]!='?'&&s[rx]!='?') now=0.0;
            else now=now*1.0/26.0;
            ans+=now;
            --lx,++rx;
        }
    }
    ans+=1.0*n;
    return ans;
}

int main(){
    scanf("%s", s);
    n = strlen(s);
    printf("%.15lf", solve());
    return 0;
}