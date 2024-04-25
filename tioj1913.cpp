#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int ans =0;
    int arr[n];
    for(auto &i:arr)cin>>i;
    for(int i =0;i<n;i++){
        int big = arr[i],small = arr[i];
        for(int j = i+1;j<n;j++){
            big = max(big,arr[j]);small = min(small,arr[j]);
            if(min(arr[i],arr[j]) == small &&max(arr[i],arr[j]) == big&&j-i == max(arr[i],arr[j])-min(arr[i],arr[j]))ans++;
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