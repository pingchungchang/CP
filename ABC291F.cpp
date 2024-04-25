#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const int mxn = 1e5+10;
vector<int> paths[mxn];
int dist[mxn];
int dist2[mxn];
string s[mxn];
bitset<mxn> vis;
main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>s[i];
        for(int j = 0;j<m;j++){
            if(s[i][j]=='1')paths[i+j+1].push_back(i);
        }
    }
    queue<int> q;
    fill(dist,dist+mxn,INT_MAX);
    dist[n] = 0;
    q.push(n);
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(auto nxt:paths[now]){
            if(dist[nxt] != INT_MAX)continue;
            dist[nxt] = dist[now]+1;
            q.push(nxt);
        }
    }
    fill(dist2,dist2+mxn,INT_MAX);
    dist2[1] = 0;
    q.push(1);
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(int j = 0;j<m;j++){
            int nxt = now+j+1;
            if(s[now][j] == '0')continue;
            if(dist2[now+j+1] != INT_MAX)continue;
            dist2[nxt] = dist2[now]+1;
            q.push(nxt);
        }
    }
    int ans[mxn];
    for(int i = 2;i<n;i++){
        ans[i] = INT_MAX;
        for(int j = 1;j<m;j++){
            for(int k = 0;k<m;k++){
                int p1 = i-j,p2 = i-j+k+1;
                if(p1>0&&p1<=n&&p2>i&&p2<=n&&s[p1][k] == '1'){
                    // cout<<i<<' '<<p1<<' '<<p2<<endl;
                    ans[i] = min(ans[i],dist2[p1]+dist[p2]+1);
                }
            }
        }
    }
    // for(int i = 1;i<=n;i++)cout<<dist[i]<<' ';cout<<endl;
    // for(int i = 1;i<=n;i++)cout<<dist2[i]<<' ';cout<<endl;
    for(int i = 2;i<n;i++){
        if(ans[i] < INT_MAX)cout<<ans[i]<<' ';
        else cout<<-1<<' ';
    }
    return 0;
}