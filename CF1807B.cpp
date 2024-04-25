#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int ev = 0,od = 0;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        if(k&1)od += k;
        else ev += k;
    }
    if(ev>od)cout<<"Yes\n";
    else cout<<"NO\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}