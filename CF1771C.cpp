#include <bits/stdc++.h>
using namespace std;
#define ll long long

#pragma GCC optimize("O2")
#pragma GCC target("avx2")
vector<ll> primes;
const ll mxn = sqrt(1e9)+1;
bitset<mxn> isprime;
void solve(){
    ll n;
    cin>>n;
    ll arr[n];
    set<ll> st;
    for(auto &i:arr)cin>>i;
    for(auto &now:arr){
        bool flag = true;
        vector<ll> tmp;
        while(flag){
            flag = false;
            for(auto &i:primes){
                if(now%i == 0){
                    tmp.push_back(i);
                    while(now%i == 0)now/=i;
                }
            }
        }
        if(now != 1)tmp.push_back(now);
        for(auto &i:tmp){
            if(st.find(i) != st.end()){
                cout<<"YES\n";
                return;
            }
            st.insert(i);
        }
   }
   cout<<"NO\n";
   return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 2;i<mxn;i++){
        if(!isprime[i]){
            primes.push_back(i);
            for(int j = i+i;j<mxn;j+=i)isprime[j] = true;
        }
    }
    // cout<<primes.size();return 0;
    int t;
    cin>>t;
    while(t--)solve();
}