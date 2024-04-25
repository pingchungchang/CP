#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
bool vis[mxn];
int n,k;
string a,b;
bool check(int now){
    int cnt[26] = {};
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(now);
    vis[now] = true;
    while(!pq.empty()){
        auto now = pq.top();
        // cout<<now<<":"<<a[now]<<','<<b[now]<<' ';
        pq.pop();
        cnt[a[now]-'a']++;
        cnt[b[now]-'a']--;
        if(now+k<n&&!vis[now+k]){
            vis[now+k] = true;
            pq.push(now+k);
        }
        if(now+k+1<n&&!vis[now+k+1]){
            vis[now+k+1] = true;
            pq.push(now+k+1);
        }
        if(now-k>=0&&!vis[now-k]){
            vis[now-k] = true;
            pq.push(now-k);
        }
        if(now-k-1>=0&&!vis[now-k-1]){
            vis[now-k-1] = true;
            pq.push(now-k-1);
        }
    }
    // for(auto &i:cnt)cout<<i<<":";
    // cout<<'\n';
    for(auto &i:cnt)if(i != 0)return false;
    return true;
}
void solve(){
    cin>>n>>k;
    cin>>a>>b;
    fill(vis,vis+n+1,false);
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            if(!check(i)){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}