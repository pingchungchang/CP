#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
const int mxn = 110;
ll arr[mxn];
ll n,p;

bool f(ll k){
    ll tmp[mxn];
    ll mv = 0;
    for(int i = n;i>=0;i--){
        if(i != n)tmp[i] = arr[i]+mv;
        else tmp[n] = arr[n]+k;
        mv = 0;
        if(tmp[i]>=p){
            tmp[i] -= p;
            mv = 1;
        }
    }
    set<pll> st;
    for(int i = n;i>=1;i--){
        if(tmp[i]<arr[i]){
            st.insert({0,tmp[i]});
            st.insert({arr[i],p-1});
        }
        else st.insert({arr[i],tmp[i]});
    }
    if(tmp[0])st.insert({1,1});
    // for(auto &i:st)cout<<i.fs<<' '<<i.sc<<',';cout<<endl;
    if(st.begin()->fs != 0)return false;
    ll r = st.begin()->sc;
    for(auto &i:st){
        if(i.fs>r+1)return false;
        r = max(r,i.sc);
    }
    if(r == p-1)return true;
    else return false;
}
void solve(){
    cin>>n>>p;
    for(int i =1;i<=n;i++)cin>>arr[i];
    // f(0);return;
    ll l = 0,r = p-1;
    while(l != r){
        ll mid = (l+r)>>1;
        if(f(mid))r = mid;
        else l = mid+1;
    }
    cout<<l<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
