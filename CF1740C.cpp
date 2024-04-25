#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+n,greater<int>());
    int ans = arr[0]-arr[n-1];
    pair<int,int> p = {arr[0],arr[1]};
    for(int i = 2;i<n;i++){
        ans = max(ans,p.first+p.second-arr[i]*2);
        p.second = arr[i];
    }
    sort(arr,arr+n);
    p = {arr[0],arr[1]};
    for(int i = 2;i<n;i++){
        ans = max(ans,arr[i]*2-p.first-p.second);
        p.second = arr[i];
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
