#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int dp[300001] = {0};
    for(int i =0;i<300000;i++){
        dp[i] = i^dp[i-1];
    }
    for(int asd=0;asd<n;asd++){
        int mex,x;
        cin>>mex>>x;
        int k = dp[mex-1]^x;
        if(k ==0)cout<<mex;
        else if(k ==mex)cout<<mex+2;
        else cout<<mex+1;
        cout<<'\n';
    }
}
