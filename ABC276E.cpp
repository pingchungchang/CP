#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
#define pii pair<int,int>
#define fs first
#define sc second
bool flag = false;
pii start;
pii dir[] = {{-1,0},{1,0},{0,-1},{0,1}};
void dfs(pii now,pii par){
}
int main(){
    int n,m;
    cin>>n>>m;
    grid = vector<vector<int>>(n+2,vector<int>(m+2,-1));
    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            char c;
            cin>>c;
            if(c == 'S')start = {i,j};
            else if(c == '.')grid[i][j] = 0;
            else grid[i][j] = -1;
        }
    }
    int idx = 0;
    queue<pii> q;
    for(auto &i:dir){
        if(grid[start.fs+i.fs][start.sc+i.sc] != -1){
            grid[start.fs+i.fs][start.sc+i.sc] = ++idx;
            q.push({start.fs+i.fs,start.sc+i.sc});
        }
    }
    grid[start.fs][start.sc] = -1;
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(auto &i:dir){
            pii nxt = {now.fs+i.fs,now.sc+i.sc};
            if(grid[nxt.fs][nxt.sc] == -1)continue;
            else if(grid[nxt.fs][nxt.sc] == 0){
                grid[nxt.fs][nxt.sc] = grid[now.fs][now.sc];
                q.push(nxt);
            }
            else if(grid[nxt.fs][nxt.sc] != grid[now.fs][now.sc]){
                cout<<"Yes\n";
                return 0;
            }
        }
    }
    cout<<"No\n";
    return 0;

}