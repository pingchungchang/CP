#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn = 1e7;
bitset<mxn> isp;
vector<ll> primes;


ll sq(ll k){
    ll re = 0;
    for(ll i = 32;i>=0;i--){
        ll tmp = re|(1LL<<i);
        if((__int128_t)tmp*tmp<=k)re = re|(1LL<<i);
    }
    return re;
}
void solve(){
    ll n;
    cin>>n;
    for(auto &i:primes){
        if(n%i != 0)continue;
        if(n%(i*i) == 0){
            ll tmp = n/(i*i);
            cout<<i<<' '<<tmp<<'\n';
            return;
        }
        ll tmp = sq(n/i);
        cout<<tmp<<' '<<i<<'\n';
        return;
    }
    cout<<"-1\n";
    return;
}
int main(){
    isp[0] = isp[1] = true;
    for(int i = 2;i<mxn;i++){
        if(!isp[i]){
            for(int j = i+i;j<mxn;j+=i)isp[j] = true;
            primes.push_back(i);
        }
    }
    int t;
    cin>>t;
    while(t--)solve();
}