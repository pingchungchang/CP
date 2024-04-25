#include <bits/stdc++.h>
using namespace std;


#define ll long long

vector<vector<ll>>v;
ll n,m;

bool f(ll now){
    bool b = false;
    set<ll> st;
    for(ll i = 0;i<m;i++){
        ll t = 0;
        for(ll j= 0;j<n;j++){
            if(v[i][j]>=now){
                t++;
                st.insert(j);
            }
        }
        if(t>1)b = true;
    }
    if(st.size() == n&&b == true)return true;
    else return false;
}
void solve(){
    cin>>m>>n;
    v = vector<vector<ll>>(m,vector<ll>(n));
    for(ll i = 0;i<m;i++){
        for(ll j = 0;j<n;j++)cin>>v[i][j];
    }
    ll l = 0,r = INT_MAX;
    while(l != r){
        ll mid = (l+r+1)/2;
        if(f(mid)){
            l = mid;
        }
        else r = mid-1;
    }

    cout<<l<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
