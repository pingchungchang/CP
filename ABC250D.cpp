#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 1e6+10;
vector<ll> primes;
bitset<mxn> isp;
int main(){
    for(int i = 2;i<mxn;i++){
        if(!isp[i]){
            primes.push_back(i);
            for(int j = i+i;j<mxn;j+=i)isp[j] = true;
        }
    }
    ll n;
    ll ans = 0;
    cin>>n;
    for(int i = 1;i<primes.size();i++){
        for(int j = 0;j<i&&(__int128_t)primes[i]*primes[i]*primes[i]*primes[j]<=n;j++)ans++;
    }
    cout<<ans;
}