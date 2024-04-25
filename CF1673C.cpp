#include <bits/stdc++.h>
using namespace std;


#define ll long long
bool ispal(int k){
    string s = to_string(k);
    int nn = s.size();
    for(int i = 0;i<nn;i++){
        if(s[i] != s[nn-i-1])return false;
    }
    return true;
}

const int mxn = 1e4*4+10;
const ll mod = 1e9+7;

int main(){
    ll dp[mxn];
    memset(dp,0LL,sizeof(dp));
    dp[0] = 1;
    for(int i = 1;i<=mxn;i++){
        if(ispal(i) == false)continue;
        for(int j = i;j<mxn;j++){
            dp[j] += dp[j-i];
            dp[j] %= mod;
        }
    }
    int t;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    for(int i = 0;i<t;i++){
        int k;
        cin>>k;
        cout<<dp[k]<<'\n';
    }
}
