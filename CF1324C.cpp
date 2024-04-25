#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int pre = 0;
    int ans = 0;
    s +='R';
    for(auto &i:s){
        if(i == 'R'){
            ans = max(ans,pre+1);
            pre = 0;
        }
        else pre++;
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