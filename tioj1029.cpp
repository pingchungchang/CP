#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int items[n];
    for(int i =0;i<n;i++)cin>>items[i];
    pair<int,int> dp[n][n];
    for(int i =0;i<n;i++){
        dp[i][i] = make_pair(items[i],0);
    }
    int turn = 0;

}
