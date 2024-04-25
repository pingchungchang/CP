#include <bits/stdc++.h>
using namespace std;


#define ll long long
void solve(){
    int n;
    cin>>n;
    multiset<ll> st;
    for(int i = 0;i<n;i++){
        ll k;
        cin>>k;
        st.insert(k);
    }
    priority_queue<ll,vector<ll>,less<ll>> pq;
    vector<ll> ans;
    ll tmp = 0;
    for(int i = 0;i<=n;i++){
        if(n-st.size()<i){
            ans.push_back(-1);
            continue;
        }
        ll x = 0;
        if(i != 0){
            tmp += i-1-pq.top();
            pq.pop();
        }
        while(!st.empty()&&*st.begin() == i){
            x++;
            st.erase(st.begin());
            pq.push(i);
        }
        //cout<<tmp<<' '<<x<<'\n';
        ans.push_back(tmp+x);
    }
    for(auto i:ans)cout<<i<<' ';cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
