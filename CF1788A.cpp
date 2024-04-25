#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n+1] = {};
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        if(arr[i] == 1)arr[i] = 0;
        else arr[i] = 1;
        arr[i] += arr[i-1];
    }
    for(int i = 1;i<=n;i++){
        if(arr[i]==arr[n]-arr[i]){
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