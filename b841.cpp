#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            int k;
            cin>>k;
            v[i][j] = k;
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(j!=m-1&&v[i][j] == v[i][j+1]&&v[i][j] != -1){
                ans++;
                v[i][j] = -1;
                v[i][j+1] = -1;
            }
            else if(i!=n-1&&v[i][j] == v[i+1][j]){
                ans++;
                v[i][j] = -1;
                v[i+1][j] = -1;
            }
        }
    }
    printf("%d",ans);
}