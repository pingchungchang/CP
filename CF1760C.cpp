#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n],b[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        b[i] = arr[i];
    }
    sort(b,b+n);
    for(int i = 0;i<n;i++){
        if(arr[i] != b[n-1])cout<<arr[i]-b[n-1]<<' ';
        else cout<<-b[n-2]+arr[i]<<' ';
    }
    cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}