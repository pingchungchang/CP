#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<char> s1,s2;
    for(int i = 0;i<n;i++){
        if(i&1)s2.insert(s[i]);
        else s1.insert(s[i]);
    }
    for(auto &i:s1){
        if(s2.find(i) != s2.end()){
            cout<<"NO\n";
            return;
        }
    }
    for(auto &i:s2){
        if(s1.find(i) != s1.end()){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}