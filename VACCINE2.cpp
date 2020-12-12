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
        int n,d;
        cin>>n>>d;

        vector<int> age(n);
        int risk=0,notRisk;
        for(int i=0;i<n;i++){
            cin>>age[i];
            if(age[i]<=9 || age[i]>=80)
                ++risk;
        }

        notRisk = n-risk;
        
        long day=1;

        while(risk>0){
            risk = risk-d;
            ++day;
        }

        while(notRisk>0){
            notRisk = notRisk-d;
            ++day;
        }

        day = day==1?1:day-1;

        cout<<day<<endl;
    }
    return 0;
}