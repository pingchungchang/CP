#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a[4] = {};
    for(auto &i:a)cin>>i;
    int m[2] = {};
    m[0] = m[1] = a[0];
    int ans = a[0];
    if(a[0] == 0){
        cout<<1<<'\n';
        return;
    }
    int d = min(a[1],a[2]);
    ans += d*2;
    int hp = a[0];
    a[1] -= d,a[2] -= d;
    if(a[1]>0){
        ans += min(hp+1,a[1]);
        hp -= min(hp+1,a[1]);
    }
    if(a[2]>0){
        ans += min(hp+1,a[2]);
        hp -= min(hp+1,a[2]);
    }
    ans += min(max(hp+1,0),a[3]);
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}