#include <bits/stdc++.h>

using namespace std;

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

int main(){
    int d1,v1,d2,v2,p;

    cin>>d1>>v1>>d2>>v2>>p;

    int vac=0,day=1;

    while(vac<p){
        if(day>=d1) vac+=v1;
        if(day>=d2) vac+=v2;
        ++day;
    }
    cout<<(day==1?1:day-1);
    return 0;
}