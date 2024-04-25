#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    set<ll>st;
    int n;
    cin>>n;
    ll sum = 0;
    for(int i= 0;i<n;i++){
        ll k;
        cin>>k;
        st.insert(k*n);
        sum += k;
    }
    if(st.find(sum) != st.end()){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
