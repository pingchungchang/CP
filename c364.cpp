#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n+2);
    v[0] = INT_MAX;
    v[n+1] = INT_MAX;
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        v[i] = k;
    }
    vector<int> dp(n+2,0);
    for(int i = 1;i<=n;i++){
        if(v[i]>v[i-1]){
            dp[i]+=dp[i-1];
            
        }
    }
}