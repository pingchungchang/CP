#include <bits/stdc++.h>
using namespace std;


void solve(){
    set<int> st;
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<n;i++){
        int k;
        cin>>k;
        st.insert(k);
    }
    cout<<*st.upper_bound(m)<<' '<<*(--st.upper_bound(m))<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}