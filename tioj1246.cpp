#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 1202;
int dist[mxn][mxn];
queue<pii>q;
pii dir[] = {{5,0},{0,5},{-5,0},{0,-5},{3,4},{4,3},{-3,4},{-4,3},{-4,-3},{-3,-4},{3,-4},{4,-3}};
vector<pii>bar[] = {
{{1,0},{2,0},{3,0},{4,0},{5,0}},
{{0,1},{0,2},{0,3},{0,4},{0,5}},
{{-1,0},{-2,0},{-3,0},{-4,0},{-5,0}},
{{0,-1},{0,-2},{0,-3},{0,-4},{0,-5}},
{{1,1},{1,2},{2,2},{2,3},{3,4}},
{{1,1},{2,1},{2,2},{3,2},{4,3}},
{{-1,1},{-1,2},{-2,2},{-2,3},{-3,4}},
{{-1,1},{-2,1},{-2,2},{-3,2},{-4,3}},
{{-1,-1},{-2,-1},{-2,-2},{-3,-2},{-4,-3}},
{{-1,-1},{-1,-2},{-2,-2},{-2,-3},{-3,-4}},
{{1,-1},{1,-2},{2,-2},{2,-3},{3,-4}},
{{1,-1},{2,-1},{2,-2},{3,-2},{4,-3}}
};
int n,m,k;
void solve(){
    for(int i = 0;i<n;i++)fill(dist[i],dist[i]+m,-1);
    while(k--){
        int a,b;
        cin>>a>>b;
        dist[a][b] = -2;
    }
    /*
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)cout<<dist[i][j]<<' ';
        cout<<endl;
    }
    */
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    dist[x1][y1] = 0;
    q.push({x1,y1});
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(int i = 0;i<12;i++){
            pii nxt = {now.fs+dir[i].fs,now.sc+dir[i].sc};
            if(nxt.fs>=0&&nxt.fs<n&&now.sc>=0&&now.sc<m&&dist[nxt.fs][nxt.sc] == -1){
                bool flag = true;
                for(auto tmp:bar[i]){
                    pii tt = {tmp.fs+now.fs,tmp.sc+now.sc};
                    if(dist[tt.fs][tt.sc] == -2){
                        flag = false;
                        break;
                    }
                }
                //cout<<nxt.fs<<' '<<nxt.sc<<":"<<flag<<endl;
                if(flag){
                    q.push(nxt);
                    dist[nxt.fs][nxt.sc] = dist[now.fs][now.sc]+1;
                }
            }
        }
    }
    if(dist[x2][y2] < 0)cout<<"No Way!\n";
    else cout<<dist[x2][y2]<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m>>k){
        if(n == 0&&m == 0&&k == 0)return 0;
        solve();
    }
}
