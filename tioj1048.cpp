#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n,m;

ll fac[13] = {};
void solve(){
    m--;
    m %= fac[n];
    // m++;
    int arr[n];
    bool done[n] = {};
    for(int i = 0;i<n;i++)arr[i] = i;
    for(int i = 0;i<n;i++){
        int k = m/fac[n-i-1];
        m %= fac[n-i-1];
        int c = 0,cnt = 0;
        for(int j = 0;j<n;j++){
            if(!done[j])cnt++;
            if(cnt == k+1){c = j;break;}
        }
        // cout<<i<<":"<<k<<' '<<c<<endl;
        arr[i] = c;
        done[c] = true;
    }
    assert(m == 0);
    for(int i = 0;i<n;i++)cout<<(char)('A'+arr[i])<<' ';cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fac[0] = fac[1] = 1;
    for(ll i = 1;i<=12;i++)fac[i] = fac[i-1]*i;
    while(cin>>n>>m&&n)solve();
}