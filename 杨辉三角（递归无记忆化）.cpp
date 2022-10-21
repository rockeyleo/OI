#include <iostream>
using namespace std;

int def(int x,int y){
    if(x==1 or y==1 or x==y){
        return 1;
    }else{
        return (def(x,y-1)+def(x-1,y-1));
    }
}

int main(){
    int x,y;
    cin>>x>>y;
    cout<<def(x,y);
}