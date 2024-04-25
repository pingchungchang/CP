#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5+10;
bitset<mxn> dp;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    cin>>m;
    set<int> bar;
    while(m--){
        int k;
        cin>>k;
        bar.insert(k);
    }
    int x;
    cin>>x;
    dp[0] = true;
    for(int i = 1;i<=x;i++){
        if(bar.find(i) != bar.end())continue;
        for(auto &j:arr){
            if(j>i)continue;
            dp[i] = dp[i]|dp[i-j];
        }
    }
    if(dp[x])cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}