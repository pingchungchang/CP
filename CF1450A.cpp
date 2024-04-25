#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    cout<<s<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}