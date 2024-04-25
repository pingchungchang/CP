#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    multiset<pair<int,int>> st;
    int ans = 0;
    for(int i = 0;i<n;i++){
        pair<int,int> p;
        cin>>p.first>>p.second;
        if(st.find(make_pair(p.second,p.first)) != st.end()){
            st.erase(st.find(make_pair(p.second,p.first)));
            ans++;
        }
        else st.insert(p);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
