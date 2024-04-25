#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int brr[n-1];
    for(auto &i:brr)cin>>i;
    int ans[n] = {};
    memset(ans,-1,sizeof(ans));
    for(int i = 0;i<n-1;i++){
        if(ans[i] == -1)ans[i] = brr[i];
        if(ans[i+1] == -1)ans[i+1] = brr[i];
        if(ans[i]>brr[i])ans[i] = brr[i];
        if(ans[i+1]>brr[i])ans[i+1] = brr[i];
    }
    for(auto &i:ans)cout<<i<<' ';cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}