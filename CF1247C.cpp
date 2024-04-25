#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll bits(ll now){
    ll ans = 0;
    while(now != 0){
        if((now&1) != 0)ans++;
        now>>=1;
    }
    return ans;
}
int main(){
    ll n,p;
    cin>>n>>p;
    for(ll i = 1;i<63;i++){
        ll tmp = n-p*i;
        if(i<=tmp&&bits(tmp)<=i){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;

}
