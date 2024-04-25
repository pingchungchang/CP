#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    int arr[n],brr[n];
    for(auto &i:arr)cin>>i;
    for(auto &i:brr)cin>>i;
    for(int i = 0;i<n;i++){
        if(arr[i]>brr[i])swap(arr[i],brr[i]);
    }
    if(*max_element(arr,arr+n) == arr[n-1]&&(*max_element(brr,brr+n)) == brr[n-1])cout<<"YES\n";
    else cout<<"NO\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}