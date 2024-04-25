#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n,k;
vector<ll>v;


void solve(){
    cin>>n>>k;
    v = vector<ll>(n);
    for(ll i = 0;i<n;i++)cin>>v[i];
    ll l = 0,r = n;
    set<ll> st;
    for(auto i:v)st.insert(i);
    ll mex = 0;
    ll miss = 0;
    sort(v.begin(),v.end());
    vector<pair<ll,ll>> vv;
    for(ll i = 0;i<n;i++){
        if(vv.empty()||vv.back().first != v[i])vv.push_back(make_pair(v[i],1));
        else vv.back().second++;
    }
    for(ll i = 0;i<n;i++){
        if(st.find(i) == st.end())miss++;
        else st.erase(i);
        if(miss<=k)mex = i+1;
    }
    //cout<<"MEX:"<<mex<<'\n';
    //for(auto i:vv)cout<<i.first<<' '<<i.second<<',';cout<<'\n';
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(ll i = vv.size()-1;i>=0&&vv[i].first>=mex;i--){
        pq.push(vv[i].second);
    }
    ll ans = pq.size();
    while(k>0&&!pq.empty()){
        if(pq.top()>k){
            k = 0;
            break;
        }
        ans --;
        k -= pq.top();
        pq.pop();
    }
    cout<<ans<<'\n';
    return;

}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
