#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    for(int i = 1;i<s.size();i++){
        if(s[i] == s[i-1])return false;
    }
    return true;
}
void solve(){
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    int same = 0;
    for(int i = 0;i<n-1;i++){
        if(a[i] == a[i+1])same++;
    }
    while(a.size()>=2&&!check(a)){
        b.push_back(a.back());
        a.pop_back();
    }
    while(b.size()>=2&&!check(b)){
        a.push_back(b.back());
        b.pop_back();
    }
    if(check(a)&&check(b)){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}