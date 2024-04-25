#include <bits/stdc++.h>
using namespace std;

void solve(){
    string n;
    cin>>n;
    string ans[2] = {string(n.size(),0),string(n.size(),0)};
    bool flag = false;
    for(int i = 0;i<n.size();i++){
        int now = n[i]-'0';
        ans[0][i] = ans[1][i] = now/2+'0';
        if(now&1){
            ans[flag][i]++;
            flag ^= 1;
        }
    }
    cout<<stoi(ans[0])<<' '<<stoi(ans[1])<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}