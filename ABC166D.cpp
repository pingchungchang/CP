#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    set<pair<ll,ll>> st;
    ll lim = pow(1e9,0.2)+1;
    lim *=2;
    ll x;
    cin>>x;
    for(ll i = -lim;i<=lim;i++)st.insert(make_pair(i*i*i*i*i,i));
    for(auto i:st){
        ll nxt = -x+i.first;
        auto it =st.upper_bound(make_pair(nxt,INT_MAX));
        if(it == st.begin())continue;
        --it;
        if(it->first == nxt){
            cout<<i.second<<' '<<it->second;
           // cout<<endl<<i.first<<' '<<it->first<<endl;
            return 0;
        }
    }
    cout<<"ERROR";
}
