#include <bits/stdc++.h>
using namespace std;

int n;
const int inf = 1e9;
void solve(){
    int dist[n][n];
    memset(dist,inf,sizeof(dist));
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>dist[i][j];
            if(!dist[i][j])dist[i][j] = inf;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j= 0;j<n;j++){
            for(int k = 0;k<n;k++){
                dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }
    int ans = inf;
    for(int i = 0;i<n;i++){
        ans = min(ans,dist[i][i]);
    }
    if(ans >= inf)cout<<-1<<'\n';
    else cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n){
        if(!n)return 0;
        solve();
    }
}