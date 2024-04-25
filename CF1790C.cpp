#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int cnt[n+1] = {};
    vector<vector<int>> v(n,vector<int>(n,0));
    for(auto &i:v){
        for(int j = 1;j<n;j++)cin>>i[j];
        cnt[i.back()]++;
    }
    int last = 0;
    for(int i = 1;i<=n;i++){
        if(cnt[i] != 1&&cnt[i] != 0)last = i;
    }
    for(auto &i:v){
        if(i.back() != last){
            for(int j = 1;j<n;j++)cout<<i[j]<<' ';
        }
    }
    cout<<last<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}