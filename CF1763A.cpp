#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[32] = {};
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        for(int j = 0;j<32;j++){
            if((1<<j)&k)arr[j]++;
        }
    }
    int ans = 0;
    for(int i = 0;i<32;i++){
        if(arr[i] != n&&arr[i] != 0)ans += (1<<i);
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