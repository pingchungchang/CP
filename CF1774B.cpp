#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll arr[m];
    for(auto &i:arr){
        cin>>i;
    }
    ll cnt = n%k;
    if(!cnt)cnt = n;
    for(auto &i:arr){
        if(n%k == 0&&i > n/k){
            cout<<"No\n";
            return;
        }
        else if(n%k != 0){
            if(i > (n+k)/k){
                cout<<"NO\n";
                return;
            }
            else if(i == (n+k)/k&&cnt<=0){
                cout<<"NO\n";
                return;
            }
            else if(i == (n/k+1))cnt--;
        }
    }
    cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}