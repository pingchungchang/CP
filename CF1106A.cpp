#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<char>> v(n+2,vector<char>(n+2,'.'));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>v[i][j];
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(v[i][j] == 'X'&&v[i+1][j+1] == 'X'&&v[i+1][j-1] == 'X'&&v[i-1][j+1] == 'X'&&v[i-1][j-1] == 'X')ans++;
        }
    }
    cout<<ans;
}
