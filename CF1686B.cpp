#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)cin>>arr[i];
    int ans = 0;
    for(int i = 1;i<n;i++){
        if(arr[i]<arr[i-1]){
            ans++;
            i++;
        }
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
