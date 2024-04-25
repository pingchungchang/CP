#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<pair<ll,ll>> items(n);
    ll nums[n];
    for(int i =0;i<n;i++){
        ll a,b;
        cin>>a>>b>>nums[i];
        items[i].first = a;
        items[i].second = b;
    }
    ll s;
    cin>>s;
    for(int i =0;i<n;i++){
        ll x = 1;
        while(x<=nums[i]){
            nums[i]-=x;
            items.push_back(make_pair(items[i].first*x,items[i].second*x));
            x*=2;
        }
        items[i].first = nums[i]*items[i].first;
        items[i].second = nums[i]*items[i].second;
    }
    vector<ll> dp(s+1,0);
    for(int i =0;i<items.size();i++){
        for(ll j = s;j>=items[i].first;j--){
            dp[j] = max(dp[j],dp[j-items[i].first]+items[i].second);
        }
    }
    cout<<dp[s];
}
