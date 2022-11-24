#include <bits/stdc++.h>
using namespace std;

template<class T>T read(){
    char ch = getchar();
    T ret = 0, f = -1;
    while(ch<'0' or ch>'9'){if(ch=='-'){f = -f;}ch = getchar();}
    while(ch>='0' and ch<='9'){ret = ret*10+ch-'0'; ch = getchar();}
    return ch*f;
}

int main(){
    cout<<(1<<10)<<endl;
    int a = read<int>(), b = read<int>();
    cout<<a<<" "<<b<<endl;
}