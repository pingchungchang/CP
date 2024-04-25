#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int total = 0;
    while(n--){
        int a,b;
        cin>>a>>b;
        total += b;
        pq.push({a,b});
    }
    if(total<m){
        cout<<"so sad\n";
        return;
    }
    int ans = 0;
    while(!pq.empty()&&m){
        if(m>pq.top().second){
            ans += pq.top().first*pq.top().second;
            m -= pq.top().second;
        }
        else{
            ans += pq.top().first*m;
            m = 0;
        }
        pq.pop();
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}