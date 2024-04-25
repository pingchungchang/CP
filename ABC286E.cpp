#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define ll long long
#define fs first
#define sc second
const int mxn = 303;
pll dist[mxn][mxn];
int main(){
    for(auto &i:dist)for(auto &j:i)j = {INT_MAX,INT_MAX};
    int n;
    cin>>n;
    int arr[n+1];
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i = 1;i<=n;i++){
        string s;
        cin>>s;
        for(int j = 1;j<=n;j++){
            if(s[j-1] == 'Y')dist[i][j] = {1,-arr[j]};
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                dist[j][k] = min(dist[j][k],{dist[j][i].fs+dist[i][k].fs,dist[j][i].sc+dist[i][k].sc});
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int s,e;
        cin>>s>>e;
        if(dist[s][e].fs >= INT_MAX){
            cout<<"Impossible\n";
            continue;
        }
        else{
            cout<<dist[s][e].fs<<' '<<-dist[s][e].sc+arr[s]<<'\n';
        }
    }
    return 0;
}