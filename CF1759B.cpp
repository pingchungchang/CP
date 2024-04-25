#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,s;
    cin>>n>>s;
    int total = 0;
    int big = 0;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        total += k;
        big = max(big,k);
    }
    int p = 0;
    while(p*(p+1)/2<total+s)p++;
    if(p*(p+1)/2 == total+s&&p>=big)cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}