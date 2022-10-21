#include <iostream>
using namespace std;

int num1[1000],num2[1000];

void insert(int num[],string str){
    for(int i=str.length()-1,j=0;i>=0;i--,j++){
        num[j] = str[i]-'0';
    }
}

int main(){
    string str1,str2;
    cin>>str1>>str2;
    insert(num1,str1);
    insert(num2,str2);
    for(int x=0;x<=5;x++){
        cout<<num1[x];
        cout<<" "<<num2[x]<<endl;
    }
}