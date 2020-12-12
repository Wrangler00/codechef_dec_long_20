#include <bits/stdc++.h>

using namespace std;

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

int main(){
    int t;
    cin>>t;

    while(t--){
        long a,b;
        cin>>a>>b;

        long long odd,even;

        if(a%2==0){
            odd = even = a/2;
        }else{
            even = a/2;
            odd = even+1;
        }

        if(b%2==0){
            odd = odd*(b/2);
            even = even*(b/2);
        }else{
            odd = odd*(b/2+1);
            even = even*(b/2);
        }

        cout<<odd+even<<endl;
    }
    return 0;
}