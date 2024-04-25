#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n;
void solve(){
    cin>>n;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    stack<ll> stk;
    set<ll> more;
    for(ll i = 0;i<n;i++){
        if(more.find(v[i]) != more.end())continue;
        else if(!stk.empty()&&stk.top() == v[i]){
            more.insert(stk.top());
            stk.pop();
        }
        else stk.push(v[i]);
    }
    if(!stk.empty()&&!more.empty()&&*more.rbegin()>stk.top()){
        cout<<more.size()+(stk.size()+1)/2<<'\n';
    }
    else if(stk.size() == 0)cout<<more.size()<<'\n';
    else cout<<more.size()+((ll)stk.size()+1)/2<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)solve();
}
