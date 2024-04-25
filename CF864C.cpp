#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll a,b,f,k;
    cin>>a>>b>>f>>k;
    vector<ll> v;
    v.push_back(0LL);
    v.push_back(f);
    ll dist[2] = {(a-f)*2,f*2};
    int now = 0;
    k--;
    while(k--){
        v.push_back(*v.rbegin()+dist[now]);
        now^=1;
    }
    if(now == 1)v.push_back(*v.rbegin()+f);
    else v.push_back(*v.rbegin()+a-f);
    int n= v.size();
    vector<ll> dp(n,INT_MAX);
    dp[0] = -1;
    for(ll i = 1;i<n;i++){
        ll lst = lower_bound(v.begin(),v.end(),v[i]-b)-v.begin();
        if(lst == i){
            cout<<-1;
            return 0;
        }
        dp[i] = dp[i-1]+1;
        dp[i] = min(dp[i],dp[lst]+1);
    }
    //for(auto i:v)cout<<i<<' ';
    //cout<<endl;
    //for(auto i:dp)cout<<i<<' ';
    //cout<<endl;
    cout<<*dp.rbegin();
}
