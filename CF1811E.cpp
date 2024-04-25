#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll k;
    cin>>k;
    string s;
    while(k>0){
        s += '0'+k%9;
        k/=9;
    }
    reverse(s.begin(),s.end());
    for(auto &i:s){
        if(i>='4')i++;
    }
    cout<<s<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}