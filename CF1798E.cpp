#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int ans[n] = {};
    fill(ans,ans+n,2);
    bool done[n] = {};
    int len[n] = {};
    for(int i = n-2;i>=0;i--){
        if(i+arr[i] == n-1){
            done[i] = true,len[i] = 1;
        }
        else if(i+arr[i]<n-1){
            if(done[i+arr[i]+1])done[i] = true,len[i] = len[i+arr[i]+1]+1;
        }
    }
    int big = 0;
    int oc[n+1] = {};
    oc[n-1] = 1;
    for(int i = n-2;i>=0;i--){
        if(done[i+1]){
            if(len[i+1] == arr[i])ans[i] = 0;
            else ans[i] = 1;
        }
        else{
            if(big>=arr[i]) ans[i] = 1;
            else if(i+1+arr[i+1]+1<=n&&oc[i+1+arr[i+1]+1]+1>=arr[i])ans[i] = 1;
            else if(oc[i+1]>=arr[i])ans[i] = 1;
            else ans[i] = 2;
        }
        oc[i] = max({big+1,(i+1+arr[i]<=n?oc[i+arr[i]+1]+1:0)});
        big = max(big,len[i]);
    }
    for(int i = 0;i<n-1;i++)cout<<ans[i]<<' ';cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}