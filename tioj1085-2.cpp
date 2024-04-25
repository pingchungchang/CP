#include <bits/stdc++.h>
using namespace std;


vector<vector<int>>dir = {{0,1,0},{0,-1,0},{1,0,0},{-1,0,0},{0,0,-1},{0,0,1}};
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<vector<int>>> v(n+2,vector<vector<int>>(m+2,vector<int>(k+2,1)));
    for(int i = 1;i<=k;i++)for(int j = 1;j<=m;j++)for(int l = 1;l<=n;l++)cin>>v[l][j][i];
    vector<vector<vector<tuple<int,int,int>>>> goneto(n+2,vector<vector<tuple<int,int,int>>>(m+2,vector<tuple<int,int,int>>(k+2,make_tuple(-1,-1,-1))));
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(1,1,1));
    if(v[1][1][1] == 1){
        cout<<"no route";
        return 0;
    }
    goneto[1][1][1] = make_tuple(1,1,1);
    while(!q.empty()){
        tuple<int,int,int> now = q.front();
        q.pop();
        int nx = get<0>(now);
        int ny = get<1>(now);
        int nz = get<2>(now);
        for(auto i:dir){
            if(v[nx+i[0]][ny+i[1]][nz+i[2]] == 0 &&goneto[nx+i[0]][ny+i[1]][nz+i[2]] == make_tuple(-1,-1,-1)){
                goneto[nx+i[0]][ny+i[1]][nz+i[2]] = make_tuple(nx,ny,nz);
                q.push(make_tuple(nx+i[0],ny+i[1],nz+i[2]));
            }
        }
    }
    vector<tuple<int,int,int>>ans;
    tuple<int,int,int> now = make_tuple(n,m,k);
    ans.push_back(now);
    int nx = get<0>(now),ny = get<1>(now),nz = get<2>(now);
    while(make_tuple(nx,ny,nz) != goneto[nx][ny][nz]){
        now = goneto[nx][ny][nz];
        nx = get<0>(now),ny = get<1>(now),nz = get<2>(now);
        if(nx == -1){
            cout<<"no route";
            return 0;
        }
        ans.push_back(now);
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0;i<ans.size();i++){
        auto now = ans[i];
        cout<<"("<<get<0>(now)<<","<<get<1>(now)<<","<<get<2>(now)<<")";
        if(i != ans.size()-1)cout<<"->";
    }
    return 0;
}
