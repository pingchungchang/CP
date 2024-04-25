#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int sz = 1,ans = 0;
    char pre = '#';
    for(int i = 1;i<n;i+=2){
        if(s[i] == s[i-1]){
            if(pre != s[i]&&pre != '#')sz++;
            pre = s[i];
        }
        else{
            ans++;
        }
    }
    cout<<ans<<' '<<sz<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
