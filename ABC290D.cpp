#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n,d,k;
const ll mxn = sqrt(1e9+10);
vector<ll> primes;
bitset<mxn> isp;
ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%n;
        b>>=1;
        a = a*a%n;
    }
    return re;
}
void solve(){
    cin>>n>>d>>k;
    k--;
    ll tmp = n/__gcd(n,d);
    ll add = k/tmp;
    add = add+(k%tmp)*d;
    cout<<add%n<<'\n';
    return;
}
/*
d*x%n = 0?
*/
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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