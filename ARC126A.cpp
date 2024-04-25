#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    for(ll i =0;i<t;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        ll ans = 0;
        ll bc = min(c,b/2);
        ans += bc;
        b -= 2*bc;
        c -= bc;
        if(b<=1){
            ll ac = min(a,c/2);
            a-=ac;
            c-=2*ac;
            ans +=ac;
        }
        else{
            ll ab = min(a/2,b/2);
            ans += ab;
            a -=2*ab;
            b -=2*ab;
        }
        if(c ==1){
            if(a>=3){
                a-=3;
                c-=1;
                ans++;
            }
        }
        if(a >=0){
            ans += a/5;
        }
        cout<<ans<<'\n';
    }
}
//103 3 2
