#include <iostream>

using namespace std;

struct stu{
    int id;
    int xueye;
    int suzhi;
    double zonghe;
    int Total(){
        return(xueye+suzhi);
    }
}; //分号不能丢

string Exc(stu &s){
    if(s.zonghe>=80 and s.Total()>140){
        return "Excellent";
    }else{
        return "Not excellent";
    }
}

stu student[1001];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>student[i].id>>student[i].xueye>>student[i].suzhi;
        student[i].zonghe = student[i].xueye*0.7+student[i].suzhi*0.3;
    }
    for(int i=1;i<=n;i++){
        //cout<<student[i].zonghe;
        cout<<Exc(student[i])<<endl;
    }
}