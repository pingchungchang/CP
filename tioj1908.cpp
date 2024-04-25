#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

const int mxn = 1<<22;
vector<int> able,source[50000];
int n;

void getable(int now,int bit){
    if(bit == n){
        able.push_back(now);
        return;
    }
    getable(now,bit+1);
    if(bit != 0&&!(now&(1<<(bit-1))))getable(now^(1<<bit),bit+1);
    else if(bit == 0)getable(now^1,bit+1);
}
int main(){
    cin>>n;
    getable(0,0);
    sort(able.begin(),able.end());
    // cout<<able.size();return 0;
    for(int i = 0;i<able.size();i++){
        int base = able[i];
        for(int j = 0;j<n;j++){
            if(able[i]&(1<<j)){
                if(j != 0)base |= (1<<(j-1));
                if(j != n-1)base |= (1<<(j+1));
            }
        }
        for(int j = i;j<able.size();j++){
            if(base&able[j])continue;
            source[i].push_back(j);
            if(j != i)source[j].push_back(i);
        }
    }
    int dp[2][50000] = {};
    bool roll = 0;
    int arr[n][n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++)cin>>arr[i][j];
    }
    for(int i = 0;i<n;i++){
        roll^=1;
        fill(dp[roll],dp[roll]+able.size(),0);
        for(int j = 0;j<able.size();j++){
            int tmp = 0;
            for(int k = 0;k<n;k++){
                if((1<<k)&able[j])tmp += arr[i][k];
            }
            for(auto &k:source[j]){
                dp[roll][j] = max(dp[roll][j],dp[roll^1][k]+tmp);
            }
        }
    }
    cout<<*max_element(dp[roll],dp[roll]+able.size());
    // for(int i =0 ;i<able.size();i++)total += source[i].size();cout<<total;return 0;
    return 0;
}