#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    int pref[n] = {};
    int suff[n] = {};
    for(int i = 0;i<n;i++){
        pref[i] = s[i]-'0';
        if(i !=0)pref[i] += pref[i-1];
    }
    for(int i = n-1;i>=0;i--){
        suff[i] = s[i]-'0';
        if(i != n-1)suff[i] += suff[i+1];
    }
    int ans = min(pref[n-1],n-pref[n-1]);
    for(int i = 0;i<n-1;i++){
        ans = min(ans,pref[i]+(n-i-1-suff[i+1]));
        ans = min(ans,i+1-pref[i]+(suff[i+1]));
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
