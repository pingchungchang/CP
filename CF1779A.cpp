#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin>>n>>s;
    int ans = 0;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(i != 0&&s[i] == 'R'&&s[i-1] == 'L')ans = i;
        if(s[i] == 'L')cnt |= 2;
        else cnt |= 1;
    }
    if(cnt != 3)cout<<-1<<'\n';
    else cout<<ans<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}