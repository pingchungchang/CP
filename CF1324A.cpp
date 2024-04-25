#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int p = arr[0];
    for(auto &i:arr){
        if((i^p)&1){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}