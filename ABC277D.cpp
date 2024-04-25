#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define fs first
#define sc second
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll arr[n];
    ll total = 0;
    for(auto &i:arr){
        cin>>i;
        total += i;
    }
    sort(arr,arr+n);
    vector<pair<pll,ll>> v;
    for(auto &i:arr){
        if(v.empty()||(v.back().fs.sc != i&&(v.back().fs.sc+1)%m != i)){
            v.push_back({{i,i},i});
        }
        else{
            v.back().fs.sc = i;
            v.back().sc += i;
        }
    }
    ll ans = 1e18;
    for(auto &i:v)ans = min(ans,total-i.sc);
    if(v.size()>1&&(v.back().fs.sc+1)%m == v[0].fs.fs)ans = min(ans,total-v.back().sc-v[0].sc);
    cout<<ans;
}