#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 40000;
int main(){

    vector<ll> dp(mxn,0LL);
    int arr[5] = {1,5,10,25,50};
    dp[0] = 1;
    for(int j = 0;j<5;j++){
        for(int i = arr[j];i<=mxn;i++){
            dp[i] += dp[i-arr[j]];
            if(dp[i]<0)cout<<i<<endl;
        }
    }
    int n;
    while(cin>>n){
        if(dp[n] == 1){
            printf("There is only 1 way to produce %d cents change.\n",n);
        }
        else{
            printf("There are %lld ways to produce %d cents change. \n",dp[n],n);
        }
    }
}

