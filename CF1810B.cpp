#include <bits/stdc++.h>
using namespace std;

#define ll long long
map<ll,ll> mp;

void solve(){
    ll n;
    cin>>n;
    if(n%2 == 0){
        cout<<-1<<'\n';
        return;
    }
    vector<int> ans;
    for(int i = 30;i>0;i--){
        if((1<<i)&n)ans.push_back(2);
        else ans.push_back(1);
    }
    cout<<ans.size()<<'\n';
    for(auto &i:ans)cout<<i<<' ';cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}