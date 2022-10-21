#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> set;
    int a;
    int target = 2;
    // while(cin>>a)
    //     set.push_back(a);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        set.push_back(a);
    }
    for(auto a=set.begin()+set.size()-1;a!=set.begin();a--){
        for(auto b=set.begin();b!=a;b++){
            if(*b>*(b+1))
                iter_swap(b,b+1); //注意迭代器要用特殊的swap函数
        }
    }
    auto mid = set.begin()+set.size()/2-1;
    auto flag = set.begin();
    auto end = set.end();
    auto bgn = set.begin();

    while(flag != end){
        if(target> *mid){
            flag = mid;
            mid + (end-mid)/2;
        }
        if(target< *mid){
            mid - (mid-bgn)/2;
        }
        // if(*flag == target)
        //     cout<<"done";
        flag++;
    }

    for(auto x:set){
        cout<<x<<" ";
    }
}