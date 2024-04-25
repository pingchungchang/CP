#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> o,z;
    for(int i = 0;i<n;i++){
        char c;
        cin>>c;
        if(c == '0')o.push_back(i);
        else z.push_back(i);
    }
    ll ans = o.size()*z.size();
    ll tmp = 1;
    for(int i = 1;i<o.size();i++){
        if(o[i-1]+1 == o[i])tmp++;
        else tmp = 1;
        ans = max(ans,tmp*tmp);
    }
    tmp = 1;
    for(int i= 1;i<z.size();i++){
        if(z[i-1]+1 == z[i])tmp++;
        else tmp = 1;
        ans = max(ans,tmp*tmp);
    }
    cout<<max(ans,1LL)<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}