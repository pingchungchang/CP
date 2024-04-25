#include <bits/stdc++.h>
using namespace std;

#define ll __int128_t

const int mxn = 2e5+10;
ll cnt[mxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 1;i<mxn;i++){
        for(int j = 1;j*i<mxn;j++)cnt[i*j]++;
    }
    int n;
    cin>>n;
    ll ans = 0;
    for(int i = 1;i<n;i++){
        ans += (ll)cnt[i]*cnt[n-i];
    }
    string re;
    while(ans){
        re += '0'+ans%10;
        ans /=10;
    }
    reverse(re.begin(),re.end());
    cout<<re;
}