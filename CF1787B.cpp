#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n;
    cin>>n;
    bool flag = true;
    ll ans[33];
    for(auto &i:ans)i = 1;
    while(flag){
        flag = false;
        for(ll i = 2;i*i<=n;i++){
            if(n%i == 0){
                flag = true;
                int p = 0;
                while(n%i == 0){
                    // cout<<i<<' ';
                    n/=i;
                    ans[p++]*= i;
                }
                break;
            }
        }
    }
    if(n != 1)ans[0] *= n;
    ll total = 0;
    for(auto &i:ans){
        if(i != 1)total += i;
    }
    cout<<total<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}