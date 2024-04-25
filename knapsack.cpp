#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll m;
    cin>>n>>m;
    pair<ll,ll> items[n];
    ll dp[m+1] = {0};
    for(int i =0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        items[i].first = a;
        items[i].second = b;
    }
    for(int i =0;i<n;i++){
        for(int j =m;j>=items[i].first;j--){
            dp[j] = max(dp[j],dp[j-items[i].first]+items[i].second);
        }
    }
    cout<<dp[m];
}
