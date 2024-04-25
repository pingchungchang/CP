#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        vector<vector<int>> all(n+1,vector<int>(n+1,0));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                int k;
                cin>>k;
                all[i][j] =k+all[i-1][j]+all[i][j-1]-all[i-1][j-1];
            }
        }
        int ans = all[0][0];
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                for(int l = i;l<=n;l++){
                    for(int x = j;x<=n;x++){
                        int now = all[l][x]+all[i-1][j-1]-all[l][j-1]-all[i-1][x];
                        ans = max(now,ans);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}