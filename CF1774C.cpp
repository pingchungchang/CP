#include <bits/stdc++.h>
using namespace std;

void solve(){
    int flag = 0;
    int n;
    string s;
    cin>>n>>s;
    pair<int,int> cnt = {-1,1};
    for(int i = 0;i<n-1;i++){
        flag |= s[i]-'0'+1;
        if(cnt.first != s[i])cnt = {s[i],1};
        else cnt.second++;
        cout<<i+2-cnt.second<<' ';
    }
    cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}