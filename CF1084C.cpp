#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
int main(){
    string s;
    cin>>s;
    vector<pair<char,ll>> v;
    v.push_back(make_pair('#',1LL));
    for(auto i:s){
        if(i != 'a'&&i != 'b')continue;
        if(v.rbegin()->first == i)v.rbegin()->second++;
        else v.push_back(make_pair(i,1LL));
    }
    ll ans = 1;
    for(auto i:v){
        if(i.first == 'a')ans = (ans*(i.second+1))%mod;
    }
    cout<<ans-1;
}
