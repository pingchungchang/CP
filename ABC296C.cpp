#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,x;
    cin>>n>>x;
    set<ll> st;
    for(int i = 0;i<n;i++){
        ll k;
        cin>>k;
        st.insert(k);
        if(st.find(k+x) != st.end()||st.find(k-x) != st.end()){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}