#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll n;
    cin>>n;
    set<ll>st;
    for(int i = 1;i<=n;i++)st.insert(i);
    vector<pair<ll,ll>> v(n);
    for(ll i = 0;i<n;i++){
        cin>>v[i].second>>v[i].first;
    }
    ll ans = 0;
    sort(v.begin(),v.end());
    for(int i = v.size()-1;i>=0;i--){
        ll now = v[i].second;
        ll val = v[i].first;
        auto it = st.upper_bound(now);
        if(it == st.begin()){
            continue;
        }
        else{
            st.erase(--it);
            ans += val;
        }
    }
    cout<<ans;
}
