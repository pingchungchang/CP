#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
#pragma GCC optimize("O3")
const int mxn = 1010;
int arr[mxn][mxn];
int vis[mxn][mxn];
bool goneto[mxn][mxn];
pii dir[] = {{-1,0},{0,1},{1,0},{0,-1}};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    memset(vis,-1,sizeof(vis));
    memset(arr,-1,sizeof(arr));
    pii s,e;
    cin>>s.fs>>s.sc;
    cin>>e.fs>>e.sc;
    int k;
    cin>>k;
    for(int i = 0;i<k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a][b] = c;
        vis[a][b] = INT_MAX;
    }
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
    vis[e.fs][e.sc] = INT_MAX;
    vis[s.fs][s.sc] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        pair<int,pii> now = pq.top();
        pq.pop();
        goneto[now.sc.fs][now.sc.sc] = true;
        for(auto &i:dir){
            pii nxt = {i.fs+now.sc.fs,i.sc+now.sc.sc};
            if(nxt.fs<0||nxt.sc<0)continue;
            if(!goneto[nxt.fs][nxt.sc]&&max(now.fs,arr[nxt.fs][nxt.sc])<vis[nxt.fs][nxt.sc]){
                vis[nxt.fs][nxt.sc] = max(now.fs,arr[nxt.fs][nxt.sc]);
                pq.push({vis[nxt.fs][nxt.sc],nxt});
            }
        }
    }
    /*
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)cout<<arr[i][j]<<' ';
        cout<<endl;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)cout<<vis[i][j]<<' ';
        cout<<endl;
    }
    */
    cout<<vis[e.fs][e.sc];
    return 0;
}
