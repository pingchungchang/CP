#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 5e5+10;
const ll inf = 1e9;
ll bit1[mxn],bit2[mxn];
void modify(ll bit[],int p,ll v){
    for(;p<mxn;p+=p&-p)bit[p] = max(bit[p],v);
    return;
}
ll getval(ll bit[],int p){
    ll re = -1e9;
    for(;p>0;p -= p&-p)re = max(re,bit[p]);
    return re;
}
void reset(int p){
    for(;p<mxn;p+=p&-p)bit1[p] = bit2[p] = -inf;
    return;
}
void solve(){
    ll n;
    cin>>n;
    ll arr[n+1];
    ll dp[n+1];
    fill(dp,dp+n+1,-inf*inf);
    arr[0] = 0;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    vector<ll> all = {-inf*inf,inf*inf,0LL};
    for(int i = 1;i<=n;i++){
        all.push_back(arr[i]);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(int i = 0;i<=n;i++){
        arr[i] = lower_bound(all.begin(),all.end(),arr[i])-all.begin();
    }
    ll pre[all.size()];
    fill(pre,pre+all.size(),-inf*inf);
    dp[0] = 0;
    modify(bit1,all.size()-arr[0],0);
    modify(bit2,arr[0],0);
    // for(int i = 0;i<=n;i++)cout<<arr[i]<<' ';cout<<'\n';
    for(int i = 1;i<=n;i++){
        if(arr[i]>arr[i-1])dp[i] = dp[i-1]+1;
        else if(arr[i]<arr[i-1])dp[i] = dp[i-1]-1;
        else dp[i] = dp[i-1];
        dp[i] = max(dp[i],getval(bit1,all.size()-arr[i]-1)-i);
        dp[i] = max(dp[i],getval(bit2,arr[i]-1)+i);
        dp[i] = max(dp[i],pre[arr[i]]);
        pre[arr[i]] = max(dp[i],pre[arr[i]]);
        modify(bit1,all.size()-arr[i],dp[i]+i);
        modify(bit2,arr[i],dp[i]-i);
    }
    for(int i = 1;i<=all.size();i++)reset(i);
    // for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';cout<<'\n';
    // for(int i = 1;i<=n;i++)cout<<pre[i]<<' ';cout<<'\n';
    // for(auto &i:all)cout<<i<<' ';cout<<'\n';
    cout<<dp[n]<<'\n';
    // cout<<'\n';
    return;
}
int main(){
    fill(bit1,bit1+mxn,-inf);
    fill(bit2,bit2+mxn,-inf);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}