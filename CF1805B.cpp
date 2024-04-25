#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,vector<int>> mp;
    if(n == 1){
        cout<<s<<'\n';
        return;
    }
    for(int i = 0;i<n;i++){
        mp[s[i]].push_back(i);
    }
    if(mp.begin()->sc.size()-(s[0] == mp.begin()->fs) != 0){
        cout<<mp.begin()->fs;
        for(int i = 0;i<n;i++){
            if(i == mp.begin()->sc.back())continue;
            cout<<s[i];
        }
        cout<<'\n';
        return;
    }
    else{
        cout<<s<<'\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}