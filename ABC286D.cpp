#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")

const int mxn = 1e4+10;
bitset<mxn> dp;

int main(){
    int n,x;
    cin>>n>>x;
    dp[0] = 1;
    for(int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        while(b--)dp = dp|(dp<<a);
    }
    if(dp[x])cout<<"Yes";
    else cout<<"No";
}