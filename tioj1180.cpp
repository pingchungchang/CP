#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll fac[14];
int cnt= 1;
void solve(){
    cout<<"Case #"<<cnt++<<":\n";
    int n;
    cin>>n;
    for(int i = 0;i<=n;i++){
        cout<<"TFCIS"<<i<<"="<<fac[i]<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fac[0] = 1;
    for(int i = 1;i<=13;i++)fac[i] = fac[i-1]*i;
    int t;
    cin>>t;
    while(t--)solve();
}