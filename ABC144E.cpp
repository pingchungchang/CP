#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 2e5+10;
ll a[mxn],b[mxn];
ll n;
ll f(ll tar){
    ll cnt = 0;
    for(int i = 0;i<n;i++){
        ll tmp = max(0LL,a[i]-tar/b[i]);
        cnt += tmp;
    }
    return cnt;
}


int main(){
    ll k;
    cin>>n>>k;
    for(int i = 0;i<n;i++)cin>>a[i];
    for(int i = 0;i<n;i++)cin>>b[i];
    sort(a,a+n);
    sort(b,b+n,greater<ll>());
    // cout<<"HI"<<endl;return 0;
    ll l = 0,r = 1e18;
    while(l != r){
        ll mid = (l+r)>>1;
        if(f(mid)>k)l = mid+1;
        else r = mid;
    }
    cout<<l;
}