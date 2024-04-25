#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll h,c,t;
    cin>>h>>c>>t;
    if(t*2 == h+c){
        cout<<2<<'\n';
        return;
    }
    else if(t*2<=h+c){
        cout<<2<<'\n';
        return;
    }
    ll l = 1,r = 1e9;
    pair<long double,ll> ans = {h-t,1};
    while(l != r){
        ll mid = (l+r)>>1;
        if((double)(h*(mid+1)+c*mid)/(mid*2+1)<=t)r = mid;
        else l = mid+1;
    }
    ans = min(ans,{abs((double)(h*(l+1)+c*l)/(l*2+1)-t),l*2+1});
    l--;
    ans = min(ans,{abs((double)(h*(l+1)+c*l)/(l*2+1)-t),l*2+1});
    cout<<ans.second<<'\n';
    // cout<<ans.first<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}