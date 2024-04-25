#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxn = 2e5+10;
ll bit[mxn];
void modify(int p,int v){
    for(;p<mxn;p+=p&-p)bit[p] += v;
    return;
}
ll getval(ll s,ll e){
    ll re = 0;
    for(;e>0;e-= e&-e)re += bit[e];
    s--;
    for(;s>0;s-= s&-s)re -= bit[s];
    return re;
}
#define pll pair<ll,ll>
#define fs first
#define sc second
pll arr[mxn];
vector<ll> all;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)cin>>arr[i].fs;
    for(int i = 0;i<n;i++){
        cin>>arr[i].sc;
        all.push_back(arr[i].fs-arr[i].sc);
    }
    all.push_back(-1e18);
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    ll ans = 0;
    for(int i = 0;i<n;i++){
        ll lim = arr[i].sc-arr[i].fs;
        ll pos = upper_bound(all.begin(),all.end(),lim)-all.begin();
        ans += getval(pos,mxn-1);
        modify(lower_bound(all.begin(),all.end(),arr[i].fs-arr[i].sc)-all.begin(),1);
    }
    cout<<ans;
}