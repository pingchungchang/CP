#include <bits/stdc++.h>
using namespace std;

string s = "314159265358979323846264338327";
void solve(){
    string t;
    cin>>t;
    int ans = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i] != t[i])break;
        ans++;
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
