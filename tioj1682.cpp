#include <bits/stdc++.h>
using namespace std;

int n;
void solve(){
    int arr[n];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" \n"[i == n-1];
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n)solve();
}