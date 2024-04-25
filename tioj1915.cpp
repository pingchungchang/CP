#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 5e5+10;
vector<int> paths[mxn];
int cnt[mxn];
int normal[mxn];

void solve(){
    int n,m;
    cin>>n>>m;
    fill(normal,normal+n,0);
    fill(cnt,cnt+n,0);
    for(int i = 0;i<n;i++)paths[i].clear();
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        normal[min(a,b)]++;
        paths[a].push_back(b);
        paths[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    int ans= 0;
    for(int i = 0;i<n;i++)pq.push({(int)paths[i].size(),i});
    while(!pq.empty()){
        auto tmp = pq.top();
        pq.pop();
        int now = tmp.sc;
        if(cnt[now] <= -1)continue;
        ans = max(ans,tmp.fs);
        cnt[now] = -1;
        for(auto &i:paths[now]){
            cnt[i]--;
            if(cnt[i]>=0)pq.push({cnt[i],i});
        }
    }
    cout<<*max_element(normal,normal+n)<<' '<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
