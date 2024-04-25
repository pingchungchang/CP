#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v;
    v.push_back(INT_MAX);
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        if(v.back() == k)continue;
        else v.push_back(k);
    }
    v.push_back(INT_MAX);
    int cnt = 0;
    for(int i = 1;i<v.size()-1;i++){
        if(v[i-1]>v[i]&&v[i+1]>v[i])cnt++;
    }
    if(cnt == 1)cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}