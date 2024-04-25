#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> dif(11,-1);
    for(int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        dif[b] = max(dif[b],a);
    }
    int ans= 0;
    for(int i = 1;i<=10;i++){
        ans += dif[i];
        if(dif[i] == -1){
            cout<<"MOREPROBLEMS\n";
            return;
        }
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
