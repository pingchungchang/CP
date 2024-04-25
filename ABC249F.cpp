#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct node{
    int s;
    vector<ll> v;
};
int main(){
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> v;
    v.push_back({0});
    for(int i = 0;i<n;i++){
        ll t,x;
        cin>>t>>x;
        if(t == 1){
            v.push_back({x});
        }
        else (*v.rbegin()).push_back(x);
    }

    /*cout<<endl;
    for(auto i:v){
        for(auto j:i)cout<<j<<' ';
        cout<<endl;
    }*/

    vector<ll> sums(v.size(),0);
    for(ll i = 0;i<v.size();i++){
        for(ll j = 1;j<v[i].size();j++){
            sums[i] += v[i][j];
        }
    }

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> dif;

    ll sum = 0;
    for(auto i:sums)sum += i;
    ll ans = LONG_LONG_MIN;
    for(ll i = 0;i<v.size();i++){
        for(ll j= 1;j<v[i].size();j++){
            pq.push(make_pair(v[i][j],i));
        }
    }
    for(ll i =0;i<v.size();i++){
        if(v.size()-i-1>k){
            sum -= sums[i];
            continue;
        }
        ll lef = k-1LL*(v.size()-1-i);
        while(!dif.empty()&&dif.top().first<i){
            sum += dif.top().second;
            dif.pop();
        }
        while(dif.size()<lef&&!pq.empty()&&pq.top().first<0){
            if(pq.top().second<i){
                pq.pop();
                continue;
            }
            sum -= pq.top().first;
            dif.push(make_pair(pq.top().second,pq.top().first));
            pq.pop();
        }
        //cout<<sum<<' ';
        ans = max(ans,sum+v[i][0]);
        sum -= sums[i];
    }
    cout<<ans;
}
