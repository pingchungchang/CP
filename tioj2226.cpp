#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
const ll mxn = 2e5+10;
ll arr[mxn];
vector<ll> v[mxn];
bool cmp(int a,int b){
    return arr[a]<arr[b];
}
vector<ll> ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(int i =1;i<=n;i++)cin>>arr[i];
    for(int i = 1;i<=m;i++){
        int k;
        cin>>k;
        while(k--){
            int tmp;
            cin>>tmp;
            v[i].push_back(tmp);
        }
        sort(v[i].rbegin(),v[i].rend(),cmp);
    }
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    for(int i = 1;i<=m;i++)pq.push({0,i});
    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
        if(v[now.sc].empty())break;
        ans.push_back(v[now.sc].back());
        now.fs += arr[v[now.sc].back()];
        v[now.sc].pop_back();
        pq.push(now);
    }
    if(ans.size() != n)cout<<-1;
    else{
        for(auto &i:ans)cout<<i<<' ';return 0;
    }
}