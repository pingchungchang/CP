#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll dp[41];
void rec(int n){
    if(dp[n]!=0)return;
    rec(n-1);
    rec(n-2);
    rec(n-3);
    dp[n] = 4*dp[n-2]+dp[n-1]+2*dp[n-3];
}

int main(){
    int t;
    memset(dp,0,41*sizeof(ll));
    dp[0] =1;
    dp[1] = 1;
    dp[2] = 5;
    cin>>t;
    for(int asd=0;asd<t;asd++){
        int k;
        cin>>k;
        rec(k);
        cout<<dp[k]<<'\n';
    }
}
