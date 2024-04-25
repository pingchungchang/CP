#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll k;
void solve(){
    ll ans = 0;
    ans += 1<<(__lg(k));
    while(cin>>k){
        if(!k){
            cout<<ans<<'\n';
            return;
        }
        ans += 1<<(__lg(k));
    }
    return;
}
int main(){
    while(cin>>k){
        if(!k)return 0;
        solve();
    }
}
