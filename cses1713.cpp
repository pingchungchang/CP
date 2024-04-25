#include <bits/stdc++.h>
using namespace std;


void solve(){
    int x;
    cin>>x;
    int ans = 0;
    for(int i = 1;i<=sqrt(x);i++){
        if(x%i == 0){
            ans++;
            if(x/i != i)ans++;
        }
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)solve();
}
