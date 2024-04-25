#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a,b,q,lcm;

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    while(b != 0){
        a%= b;
        swap(a,b);
    }
    return a;
}
ll f(ll now){
    return max(now%lcm-max(a-1,b-1),0LL)+now/lcm*(lcm-max(a,b));
}
void solve(){
    cin>>a>>b>>q;
    lcm = a*b/gcd(a,b);
    for(ll i = 0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        cout<<f(r)-f(l-1)<<' ';;
    }
    cout<<'\n';

}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
