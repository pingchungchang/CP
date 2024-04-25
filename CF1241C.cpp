#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> v;
int n;
ll tar;
ll a,b,c,d;

bool f(ll now){
    ll p = 0;
    priority_queue<ll,vector<ll>,less<ll>> pq;
    for(ll i = 0;i<now;i++){
        if((i+1)%b == 0&&(i+1)%d == 0)pq.push(a+c);
        else if((i+1)%b == 0)pq.push(a);
        else if((i+1)%d == 0)pq.push(c);
    }
    ll ans = 0;
    while(!pq.empty()){
        ans += pq.top()*v[p]/100;
        pq.pop();
        p++;
    }
    //cout<<now<<' '<<ans<<' '<<tar<<endl;
    if(ans>=tar)return true;
    else return false;
}
void solve(){
    cin>>n;
    v = vector<ll>(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    cin>>a>>b>>c>>d;
    cin>>tar;
    ll l = 0,r = n;
    sort(v.rbegin(),v.rend());
    while(l != r){
        ll mid = (l+r)/2;
        if(f(mid))r = mid;
        else l = mid+1;
    }
    if(l == n&&f(r) == false)cout<<-1<<'\n';
    else cout<<l<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
