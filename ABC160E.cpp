#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
priority_queue<pll,vector<pll>,less<pll>> pq;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    for(int i = 0;i<a;i++){
        ll k;
        cin>>k;
        pq.push({k,1});
    }
    for(int i = 0;i<b;i++){
        ll k;
        cin>>k;
        pq.push({k,2});
    }
    for(int i = 0;i<c;i++){
        ll k;
        cin>>k;
        pq.push({k,0});
    }
    ll total = x+y;
    ll ans = 0;
    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
        if(!total)break;
        if(now.sc == 0){
            total--;
            ans += now.fs;
        }
        else if(now.sc == 1){
            if(x){
                ans += now.fs;
                total--;
                x--;
            }
        }
        else{
            if(y){
                total--;
                ans += now.fs;
                y--;
            }
        }
    }
    cout<<ans;
}