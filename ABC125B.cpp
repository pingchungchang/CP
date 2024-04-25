#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
#define pll pair<ll,ll>

int main(){
    int n;
    cin>>n;
    pll arr[n];
    for(auto &i:arr)cin>>i.fs;
    for(auto &i:arr)cin>>i.sc;
    ll ans = 0;
    for(int i = 0;i<(1<<n);i++){
        pll total = {0,0};
        for(int j = 0;j<n;j++){
            if(i&(1<<j)){
                total.fs += arr[j].fs;
                total.sc += arr[j].sc;
            }
        }
        ans = max(ans,total.fs-total.sc);
    }
    cout<<ans;
}
