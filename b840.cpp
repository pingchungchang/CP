#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> farm(n+1,vector<int>(n+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            int k;
            cin>>k;
            farm[i][j] = k;
        }
    }
    vector<vector<int>> sums(n+1,vector<int>(n+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            sums[i][j] = sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+farm[i][j];
        }
    }
    int ans = 0;
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            for(int x = 1;x<=n;x++){
                for(int y = 1;y<=n;y++){
                    if(x<=i||y<=j) continue;
                    //if(sums[x][y]-sums[x][j]-sums[i][y]+sums[i][j]>ans) cout<<x<<' '<<y<<' '<<i<<' '<<j<<endl;
                    ans = max(ans,sums[x][y]-sums[x][j]-sums[i][y]+sums[i][j]);
                }
            }
        }
    }
    cout<<ans<<endl;
}
