#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n;
    cin>>n;
    ll total = 0;
    for(int i = 0;i<n;i++){
        ll tmp;
        cin>>tmp;
        total += tmp;
    }
    cout<<abs(total)<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}