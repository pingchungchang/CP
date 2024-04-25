#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n+2,vector<char>(m+2,'X'));
    vector<vector<int>> ans;
    for(int i = 1;i<=n;i++)for(int j= 1;j<=m;j++)cin>>v[i][j];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(v[i][j] == 'X')continue;
            if(v[i+1][j] == 'O'&&v[i-1][j] == 'O'&&v[i][j+1] == 'O')ans.push_back({j,i-1,j,i,j,i+1,j+1,i});
            if(v[i][j+1] == 'O'&&v[i][j-1] == 'O'&&v[i+1][j] == 'O')ans.push_back({j-1,i,j,i,j,i+1,j+1,i});
            if(v[i+1][j] == 'O'&&v[i-1][j] == 'O'&&v[i][j-1] == 'O')ans.push_back({j-1,i,j,i-1,j,i,j,i+1});
            if(v[i][j+1] == 'O'&&v[i][j-1] == 'O'&&v[i-1][j] == 'O')ans.push_back({j-1,i,j,i-1,j,i,j+1,i});
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int i = 0;i<ans.size();i++){
        cout<<"("<<ans[i][0]-1<<","<<ans[i][1]-1<<")  ("<<ans[i][2]-1<<","<<ans[i][3]-1<<")  ("<<ans[i][4]-1<<","<<ans[i][5]-1<<")  ("<<ans[i][6]-1<<","<<ans[i][7]-1<<")\n";
    }
    return 0;
}
