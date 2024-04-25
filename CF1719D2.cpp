#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

void solve(){
    int n;
    cin>>n;
    int arr[n+2] = {};
    int tmp[n+2] = {};
    int pref[n+2] = {},suf[n+2] = {};
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        tmp[i] = arr[i];
    }
    for(int i = 1;i<=n;i++){
        pref[i] += pref[i-1];
        
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}