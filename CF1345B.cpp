#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll f(ll k){
    return k*(k-1)/2+k*(k+1);
}
void solve(){
    ll n;
    cin>>n;
    ll l = 0,r = 1e5+10;
    ll cnt = 0;
    while(n>0){
        while(l != r){
            ll mid = (l+r+1)>>1;
            if(f(mid)>n)r = mid-1;
            else l = mid;
        }
        if(l)cnt++;
        else break;
        n -= f(l);
        r = l;
        l = 0;
    }
    cout<<cnt;
    cout<<'\n';

}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}