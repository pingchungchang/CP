#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+n);
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == arr[0])cnt++;
    }
    cout<<n-cnt<<'\n';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}