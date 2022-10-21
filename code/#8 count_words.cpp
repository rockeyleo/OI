#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    string i,w;
    cin>>i;
    getchar();
    getline(cin,w);
    int num =0;
    string c[11];
    int k;
    int p =0;
    for(auto &x:i){
    	if(x>=65 and x<=90){
    		x+=32;
    	}
    }
    for(auto &x:w){
    	if(x>=65 and x<=90){
    		x+=32;
    	}
    }
    w = ' '+w+' ';
    i = ' '+i+' ';
    for(int a=0;a<=w.length()-1;a++){
        if(w[a] == i[0]){
        	k =0;
            for(int j=a;j<=a+i.length()-1;j++,k++){
                if(w[j]!=i[k]){
					break;
				}else if(j == a+i.length()-1)
					num +=1;
					if (a<=p)
						p=a+1;
            }
        }
    }
    if(num ==0){
    	cout<<-1<<endl;
    	return 0;	
    }
    cout<<num<<' '<<p<<endl;
    return 0;
}
