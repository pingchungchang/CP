#include <bits/stdc++.h>
using namespace std;


#define ll long long
void solve(){
    ll n;
    cin>>n;
    ll arr[n];
    for(auto &i:arr)cin>>i;
    if(*max_element(arr,arr+n) == *min_element(arr,arr+n)){
        cout<<"No\n";
        return;
    }
    ll big = *max_element(arr,arr+n);
    ll small = *min_element(arr,arr+n);
    multiset<ll> pos,neg;
    for(auto &i:arr){
        if(i>=0)pos.insert(i);
        else neg.insert(i);
    }
    vector<ll> ans;
    ll total = 0;
    while(!pos.empty()||!neg.empty()){
        while(total<=0&&!pos.empty()){
            ans.push_back(*pos.rbegin());
            total += *pos.rbegin();
            pos.erase(pos.find(*pos.rbegin()));
        }
        while(total>0){
            ans.push_back(*neg.begin());
            total += *neg.begin();
            neg.erase(neg.find(*neg.begin()));
        }
    }
    cout<<"Yes\n";
    for(auto &i:ans)cout<<i<<' ';cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}