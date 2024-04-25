#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    ll ans = 0,o = 0;
    for(auto &i:arr){
        if(i == 0)ans += o;
        else o++;
    }
    ll total = 0;
    int p = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == 0){
            p = i;
            break;
        }
    }
    arr[p] ^= 1;
    o = 0;
    for(auto &i:arr){
        if(i == 0)total += o;
        else o++;
    }
    ans = max(ans,total);
    arr[p] ^=1;
    total = o = 0;
    p = 0;
    for(int i = n-1;i>=0;i--){
        if(arr[i] == 1){
            p = i;
            break;
        }
    }
    arr[p] ^=1;
    for(auto &i:arr){
        if(i==0)total += o;
        else o++;
    }
    ans = max(ans,total);
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}