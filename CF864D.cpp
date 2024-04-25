#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n;
    cin>>n;
    map<ll,ll> mp;
    for(ll i = 1;i<=n;i++)mp[i] =0;
    mp[INT_MAX] = 0;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++){
        cin>>v[i];
        if(mp.count(v[i]) == 0){
            mp[INT_MAX]++;
            v[i] = INT_MAX;
        }
        else mp[v[i]]++;
    }
    queue<ll> q;
    for(auto it:mp){
        if(it.second < 1LL)q.push(it.first);
    }
    ll ans =0;
    for(auto &i:v){
        if(i != INT_MAX&&mp[i]==1)continue;
        if(i>q.front()||mp[i] <= -1){
            ans++;
            mp[i]--;
            i = q.front();
            mp[q.front()]++;
            q.pop();
        }
        else{
            mp[i] = -1;
        }
    }
    cout<<ans<<'\n';
    for(auto i:v)cout<<i<<' ';
}
