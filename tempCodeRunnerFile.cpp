#include <bits/stdc++.h>

using namespace std;

#define L long

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

L setBitNumber(L n) { 
    n |= n >> 1; 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
    n = n + 1; 
    return (n >> 1); 
}


unordered_map<L,queue<L>> MP;
const L LIM = 1000000002;

void makeMap(){
    MP[1] = queue<L>();

    for(L i=2;i<=LIM;i*=2){
        MP[i] = queue<L>();
    }
}

void markBits(unordered_map<L,queue<L>> &mp,L num,L ind){
    L pw = 1;
    while(num){
        if(num&1){
            mp.at(pw).push(ind);
        }
        num>>=1;
        pw*=2;
    }
}

void print(vector<L> &arr){
    for(auto &v:arr)    cout<<v<<" ";
        cout<<endl;
}
int main(){
    makeMap();
    int t;
    cin>>t;

    while(t--){
        L n,x;
        cin>>n>>x;

        vector<L> arr(n);
        
        for(L i=0;i<n;i++){
            cin>>arr[i];
        }

        unordered_map<L,queue<L>> mp=MP;

        for(L i=0;i<n;i++){
            markBits(mp,arr[i],i);
        }

        L i=0;
        while(x--){
            if(arr[i]==0){
                while(arr[i]==0 && i<n-2) ++i;
                if(arr[i]==0){
                    arr[i] ^=1;
                    arr[n-1] ^=1;
                }else{
                    L sbt = setBitNumber(arr[i]);
                    L sz = mp.at(sbt).size();

                    mp.at(sbt).pop();
                    if(sz==1){
                        arr[i] ^=sbt;
                        arr[n-1] ^=sbt;
                    }else{
                        L ind = mp.at(sbt).front();
                        arr[i]^=sbt;
                        arr[ind]^=sbt;
                        mp.at(sbt).pop();
                    }
                }
            }else{
                L sbt = setBitNumber(arr[i]);
                L sz = mp.at(sbt).size();
                
                mp.at(sbt).pop();
                if(sz==1){
                    arr[i] ^=sbt;
                    arr[n-1] ^=sbt;
                }else{
                    L ind = mp.at(sbt).front();
                    arr[i]^=sbt;
                    arr[ind]^=sbt;
                    mp.at(sbt).pop();
                }
            }
            cout<<"i :: "<<i;
            print(arr);
        }

        print(arr);
    }
    return 0;
}