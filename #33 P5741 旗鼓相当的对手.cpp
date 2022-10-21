#include <iostream>
#include <cmath>
using namespace std;
struct stu{
    string name;
    int C,E,M;
    int Total(){
        return(C+E+M);
    }
};

bool p(stu &a,stu &b){
    if(abs(a.C-b.C)<=5 and abs(a.E-b.E)<=5 and abs(a.M-b.M)<=5 and abs(a.Total()-b.Total())<=10){
        return true;
    }else{
        return false;
    }
}

stu s[1001];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].name>>s[i].C>>s[i].M>>s[i].E;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(p(s[i],s[j])){
                cout<<s[i].name<<" "<<s[j].name<<endl;
            }
        }
    }
}