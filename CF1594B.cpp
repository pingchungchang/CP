#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
int main(){
    ll t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(ll asd=0;asd<t;asd++){
        ll a,b;
        cin>>a>>b;
        ll ans = 0;
        ll base = a;
        a =1;
        while(b>0){
            if(b&1)ans +=a;
            b>>=1;
            a*=base;
            a = a%mod;
            ans = ans%mod;
        }
        cout<<ans<<'\n';
    }
}
