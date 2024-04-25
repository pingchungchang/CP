#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    cout<<(s[0]-'0'+s.back()-'0')<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}