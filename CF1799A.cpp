#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int ans[n+1] = {};
    set<int> st;
    int p = n;
    for(int i = 1;i<=m;i++){
        int k;
        cin>>k;
        if(st.find(k) != st.end())continue;
        st.insert(k);
        if(p>0)ans[p--] = i;
    }
    for(int i = 1;i<=n;i++){
        if(ans[i])cout<<ans[i]<<' ';
        else cout<<"-1 ";
    }
    cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
