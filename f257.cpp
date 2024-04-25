#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    while(cin>>n>>m){
        vector<vector<int>> v(n+2,vector<int>(n+2,0));
        for(int i =0;i<m;i++){
            int x,y;
            cin>>x>>y;
            v[x+1][y+1] = -1;
            for(int j = -1;j<=1;j++){
                for(int k = -1;k<=1;k++){
                    if(v[x+1+j][y+1+j]!= -1)v[x+1+j][y+1+k]++;
                }
            }
        }
        for(int i =1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(v[i][j] == -1) cout<<'x';
                else cout<<v[i][j];
            }
            cout<<'\n';
        }
    }
}