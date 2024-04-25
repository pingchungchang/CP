#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> all;

ll f(ll k){
    ll ans = 0;
    for(int i= all.size()-1;i>=1;i--){
        if(k>=all[i]){
            k -= all[i];
            ans++;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    all = {1,1};
    while(all.back()<INT_MAX){
        all.push_back(*all.rbegin()+*(all.rbegin()+1));
    }
    for(int i = 0;i<t;i++){
        ll k;
        cin>>k;
        if(k<=0)cout<<"iyada~\n";
        else cout<<f(k)<<'\n';
    }
}
