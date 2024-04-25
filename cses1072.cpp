#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    for(ll i =1;i<=n;i++){
        ll ans = i*i*(i*i-1)/2;
        ans -= 4*(i-2)*(i-1);
        cout<<ans;
        if(i !=n)cout<<'\n';
    }
}
