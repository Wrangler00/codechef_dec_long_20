#include <bits/stdc++.h>

using namespace std;

#define L long long

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
const L LIM = 1000000099;

void makeMap(){
    for(L i=1;i<=LIM;i*=2)
        MP[i] = queue<L>();
}

void markBits(unordered_map<L,queue<L>> &mp,vector<L> arr){
    for(L i=0;i<arr.size();i++){
        L pw = 1;
        L num=arr[i];

        while(num){
            if(num&1)   
                mp.at(pw).push(i);
            num>>=1;
            pw*=2;
        }
    }
}

void print(vector<L> &arr){
    for(auto &v:arr)    
        cout<<v<<" ";
    cout<<endl;
}

void doit(unordered_map<L,queue<L>> &mp,vector<L> &arr,L i,L n){
    L sbt = setBitNumber(arr[i]);
    L sz = mp.at(sbt).size();
    
    assert(sz>0);
    assert(i==mp.at(sbt).front());

    mp.at(sbt).pop();
    if(sz==1){
        assert(i < n-1);

        arr[i] = (long long)arr[i]^sbt;
        arr[n-1] = (long long)arr[n-1]^sbt;
    }else{
        L ind = mp.at(sbt).front();
        
        assert(i<ind);

        arr[i] = (long long)arr[i]^sbt;
        arr[ind] = (long long)arr[ind]^sbt;
        mp.at(sbt).pop();
    }
}

int main(){
    makeMap();
    int t;
    cin>>t;
    while(t--){
        unordered_map<L,queue<L>> mp=MP;
        L n,x;
        cin>>n>>x;

        vector<L> arr(n);
        
        for(L i=0;i<n;i++)  cin>>arr[i];

        markBits(mp,arr);

        L i=0;
        while(x--){
            if(arr[i]==0){
                while(arr[i]==0 && i<n-2) ++i;
                if(arr[i]==0){
                    assert(i != n-1);
                    if(x%2==0){
                        arr[i] ^=1;
                        arr[n-1] ^=1;
                    }
                    break;
                }else
                    doit(mp,arr,i,n);
            }else
                doit(mp,arr,i,n);
        }

        print(arr);
    }
    return 0;
}