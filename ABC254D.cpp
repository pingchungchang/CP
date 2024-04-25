#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll f(ll k){
    ll tmp = sqrt(k)+1;
    ll ans = 1;
    ll form = 1;
    ll i = 2;
    while(i<=tmp){
        if(k%i == 0){
            if(form == i)form = 1;
            else{
                ans *= form;
                form = i;
            }
            k /=i;
            i = 1;
            tmp = sqrt(k)+1;
        }
        i++;
    }
    if(k != form)ans *= k*form;
    return ans;
}
int main(){
    ll n;
    cin>>n;
    ll ans = 0;
    vector<ll> sq;
    for(ll i = 1;i*i<=n;i++)sq.push_back(i*i);
    //for(auto i:sq)cout<<i<<' ';cout<<endl;
    for(ll i = 1;i<=n;i++){
        ll k = f(i);
        ll tmp = upper_bound(sq.begin(),sq.end(),n/k)-sq.begin();
        ans += tmp;
        //cout<<i<<' '<<k<<' '<<tmp<<endl;
    }
    cout<<ans;
}
