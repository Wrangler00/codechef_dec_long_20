#include <bits/stdc++.h>

using namespace std;

#define L long long

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

L setBitNumber(L n){
    L res = 0;
    while(n!=0) {
        res++;
        n=n>>1;
    }
    return 1<<(res-1);
}

// L setBitNumber(L n) { 
//     n |= n >> 1; 
//     n |= n >> 2; 
//     n |= n >> 4; 
//     n |= n >> 8; 
//     n |= n >> 16; 
//     n = n + 1; 
//     return (n >> 1); 
// }


void print(vector<L> &arr){
    for(auto &v:arr)    
        cout<<v<<" ";
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        L n,x;
        cin>>n>>x;

        vector<L> arr(n);
        
        for(L i=0;i<n;i++)  cin>>arr[i];

        L i=0;
        while(x){
            if(arr[i]==0){
                if(i==n-2){
                    if(n<3 && x%2!=0){
                        arr[i] ^=1;
                        arr[n-1] ^=1;
                    }
                    break;
                }else{
                    ++i;
                    continue;   
                }
            }else{
                L sbt = setBitNumber(arr[i]);
                L j=i+1;
                
                while(j<n-1 && (arr[j]==0 || !(sbt&arr[j]) ))
                    ++j;
                arr[i]^=sbt;
                arr[j]^=sbt;
                --x;
            }
        }

        print(arr);
    }
    return 0;
}