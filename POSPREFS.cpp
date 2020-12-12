/*
 *
k=1
1 -2 -3 -4 -5

k=2
1 -2 3 -4 -5

k=3
1 -2 3 -4 5

k=4
1 -2 3 4 5 
 */


#include <bits/stdc++.h>

using namespace std;

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

void neg(int n,int k){
    for(int i=1;i<=n;i++){
        if(!k){
            cout<<i<<" ";
            continue;
        }
        if(i%2){
            cout<<i<<" ";
        }else{
            cout<<-i<<" ";
            --k;
        }
    }
}

void pos(int n,int k){
    for(int i=1;i<=n;i++){
        if(!k){
            cout<<-i<<" ";
            continue;
        }
        if(i%2){
            cout<<i<<" ";
            --k;
        }else{
            cout<<-i<<" ";
        }
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        if(k<=n-k)
            pos(n,k);
        else
            neg(n,n-k);

        cout<<endl;
    }
    return 0;
}