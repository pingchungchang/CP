#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    for(int i = 0;i<(1<<8);i++){
        int cnt = 0;
        for(auto &j:arr)cnt ^= (j^i);
        if(cnt == 0){
            cout<<i<<'\n';
            return;
        }
    }
    cout<<"-1\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}