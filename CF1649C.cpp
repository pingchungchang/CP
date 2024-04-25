#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 1e5+10;
int n,m;
int main(){
    cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>(m+1,0));
    map<ll,vector<ll>> ver,hor;
    for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++){
        cin>>v[i][j];
        ver[v[i][j]].push_back(j);
        hor[v[i][j]].push_back(i);
    }
    for(auto &i:ver)sort(i.second.begin(),i.second.end());
    for(auto &i:hor)sort(i.second.begin(),i.second.end());
    //for(auto i:ver){
    //    sort(i.second.begin(),i.second.end());
    //    cout<<i.first<<':';for(auto j:i.second)cout<<j<<' ';cout<<'\n';
    //}
    ll ans = 0;
    for(auto i:ver){
        ll total = 0;
        ll cnt = 0;
        for(auto j:i.second){
            ans += cnt*j-total;
            total += j;
            cnt++;
        }
        //cout<<i.first<<' '<<ans<<endl;
    }
    for(auto i:hor){
        ll total = 0,cnt = 0;
        for(auto j:i.second){
            ans += cnt*j-total;
            total+=j;
            cnt++;
        }
    }
    cout<<ans<<endl;
}
