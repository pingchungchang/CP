#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    if(n>=m){
        cout<<m;
        return 0;
    }
    else if((__int128_t)n*n<m){
        cout<<-1;
        return 0;
    }
    ll ans = 1e18;
    for(ll i = 1;i*i<=m*100;i++){
        ll d = (m+i-1)/i;
        if(i>n)break;
        if(d>n)continue;
        ans = min(ans,d*i);
    }
    cout<<ans;
}
/*
a*b>=m+a
(a-1)*b
*/
