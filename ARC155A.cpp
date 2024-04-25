#include <bits/stdc++.h>
using namespace std;

#define ll long long
bool isp(string s){
    for(int i =0;i<s.size()/2;i++){
        if(s[i] != s[s.size()-i-1])return false;
    }
    return true;
}
void solve(){
    ll n,k;
    string s;
    cin>>n>>k>>s;
    if(k>=n*2)k %= n*2;
    string ss = s.substr(s.size()-min(n,k),min(n,k));
    reverse(ss.begin(),ss.end());
    string tt = s.substr(0,min(n,k));
    reverse(tt.begin(),tt.end());
    while(ss.size()+tt.size()!=k)ss.pop_back();
    ss += tt;
    if(isp(ss+s) &&isp(s+ss))cout<<"Yes\n";
    else cout<<"No\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
/*
s+t
t+s
s .........r
r.........r s
s r..........sr
rsr.......sr s
*/