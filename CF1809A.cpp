#include <bits/stdc++.h>
using namespace std;



void solve(){
    string s;
    cin>>s;
    int cnt[26] = {};
    for(auto &i:s)cnt[i-'0']++;
    int big = 0;
    for(auto &i:cnt){
        if(i == 4){
            cout<<-1<<'\n';
            return;
        }
        big = max(big,i);
    }
    if(big == 1)cout<<4<<'\n';
    else if(big == 2)cout<<"4\n";
    else cout<<"6\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}