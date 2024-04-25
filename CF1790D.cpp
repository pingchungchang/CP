#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    map<int,int> cnt;
    int ans =0;
    for(auto &i:arr){
        cin>>i;
    }
    sort(arr,arr+n);
    for(auto &i:arr){
        if(cnt[i-1] != 0)cnt[i-1]--;
        cnt[i]++;
    }
    for(auto &i:cnt){
        ans += i.second;
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