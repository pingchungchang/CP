#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
void solve(){
    ll n,c,d;
    ll shift = 0;
    cin>>n>>c>>d;
    vector<int> v;
    set<int> st;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        if(st.find(k) != st.end())shift += c;
        else v.push_back(k);
        st.insert(k);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    ll ans = 1e18;
    for(int i = v.size()-1;i>=0;i--){
        ans = min(ans,shift+(v[i]-i-1)*d+c*(ll)(v.size()-i-1));
    }
    ans = min(ans,n*c+d);
    cout<<ans<<'\n';
    return;
}

main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}