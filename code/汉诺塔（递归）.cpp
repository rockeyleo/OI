#include<iostream>
using namespace std;

void Han(char a,char b,char c,int n){
    if(n==1){
        cout<<a<<"->"<<c<<endl;
    }
    else{
        Han(a,c,b,n-1);
        cout<<a<<"->"<<c<<endl;
        Han(b,a,c,n-1);
    }
}

int main(){
    int n;
    cin>>n;
    Han('A','B','C',n);
}