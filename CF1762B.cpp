#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll high(ll i){
    ll cnt = 0;
    while(i){
        cnt++;
        i>>=1;
    }
    return cnt;
}
void solve(){
    ll n;
    cin>>n;
    ll arr[n];
    for(auto &i:arr)cin>>i;
    cout<<n<<'\n';
    for(int i = 0;i<n;i++){
        cout<<i+1<<' '<<(1<<high(arr[i]))-arr[i]<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}