#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,d;
    cin>>n>>d;
    multiset<ll> st;
    for(int i = 0;i<n;i++){
        ll k;
        cin>>k;
        st.insert(k);
    }
    ll ans = 0;
    while(!st.empty()){
        ll u = *st.rbegin();
        ll k = (d)/u;
        st.erase(st.find(u));
        while(k--&&!st.empty()){
            st.erase(st.find(*st.begin()));
        }
        if(k == -1){
            ans++;
        }
    }
    cout<<ans;
}