#include <bits/stdc++.h>
using namespace std;

string y = "Yes";
void solve(){
    string s;
    cin>>s;
    if(s == y.substr(0,s.size())||s == y.substr(1,s.size())||s == y.substr(2,s.size())){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(y.size()<=55)y += "Yes";
    int t;
    cin>>t;
    while(t--)solve();
}