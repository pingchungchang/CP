#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin>>s;
    if(*s.rbegin() != 'B'){
        cout<<"NO\n";
        return;
    }
    vector<int>cnt(2,0);
    for(int i = 0;i<s.size();i++){
        cnt[s[i]-'A']++;
        if(cnt[1]>cnt[0]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
