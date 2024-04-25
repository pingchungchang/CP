#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a,ll b){
    if(b>a)swap(a,b);
    while(b != 0){
        a %= b;
        swap(a,b);
    }
    return a;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    bool neg = false;
    ll n;
    cin>>n;
    ll g = -1;
    for(ll i = 0;i<n;i++){
        ll k;
        cin>>k;
        if(g == -1)g = abs(k);
        else g = gcd(g,abs(k));
        if(k<0)neg = true;
    }
    ll q;
    cin>>q;
    for(ll i =0;i<q;i++){
        ll t;
        cin>>t;
        t -= 1115;
        if(t<=0&&neg == false){
            cout<<"No\n";
        }
        else if(abs(t)%g != 0){
            cout<<"No\n";
        }
        else cout<<"Yes\n";
    }
}
