#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
void solve(){
    ll n;
    cin>>n;
    pll arr[n];
    for(auto &i:arr){
        cin>>i.fs>>i.sc;
        if(i.fs<i.sc)swap(i.fs,i.sc);
    }
    ll big = 0;
    ll total = 0;
    for(auto &i:arr){
        big = max(i.fs,big);
        total += i.sc;
    }
    cout<<(total+big)*2<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
