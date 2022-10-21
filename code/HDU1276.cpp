#include <queue>
#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>m;
    for(int i=1;i<=m;i++){
        queue<int>q;
        cin>>n;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>3){
            int len = q.size();
            for(int i=1;i<=len/2;i++){
                int tmp = q.front(); q.pop(); q.push(tmp);
                q.pop();
            }
            for(int i=1;i<=len%2;i++){
                int tmp = q.front(); q.pop();
                q.push(tmp);
            }
            if(q.size()<=3)break;
            len = q.size();
            for(int i=1;i<=len/3;i++){
                int tmp = q.front(); q.pop(); q.push(tmp);
                tmp = q.front(); q.pop(); q.push(tmp);
                q.pop();
            }
            for(int i=1;i<=len%3;i++){
                int tmp = q.front(); q.pop();
                q.push(tmp);
            }
        }
        while(!q.empty()){
            cout<<q.front();
            if(q.size()>1)putchar(' ');
            q.pop();
        }
        cout<<endl;
    }
    return 0;
}