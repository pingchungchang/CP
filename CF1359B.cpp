#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int ans = 0;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        for(int j = 0;j<m;j++){
            if(j != m-1&&s[j+1] == s[j]&&s[j] == '.')ans += min(y,x*2),j ++;
            else if(s[j] == '.')ans += x;
        }
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}