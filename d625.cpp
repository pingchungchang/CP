#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<char>> v(n+2,vector<char>(n+2,'.'));
    for(int i = 1;i<=n;i++)for(int j = 1;j<=n;j++)cin>>v[i][j];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(v[i][j] == '*')continue;
            int ans = 0;
            for(int dx = -1;dx<=1;dx++){
                for(int dy = -1;dy<=1;dy++){
                    if(dx == 0&&dy== 0)continue;
                    if(v[i+dx][j+dy] == '*')ans++;
                }
            }
            if(ans == 0)v[i][j] = '-';
            else v[i][j] = '0'+ans;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++)cout<<v[i][j];
        cout<<'\n';
    }
}
