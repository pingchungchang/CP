#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    char c = '1';
    for(auto &i:s)c = max(i,c);
    cout<<c-'0'<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}