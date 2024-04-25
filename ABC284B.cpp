#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int ans = 0;
    while(n--){
        int k;
        cin>>k;
        if(k&1)ans++;
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}