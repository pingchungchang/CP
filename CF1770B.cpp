#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int p1 = 1,p2 = n;
    for(int i = 0;i<n;i++){
        if(i&1)arr[i] = p1++;
        else arr[i] = p2--;
    }
    for(auto &i:arr)cout<<i<<' ';cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}