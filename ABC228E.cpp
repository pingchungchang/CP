#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 5050;
const ll inf = 1e18;
ll A[mxn],C[mxn];
ll dp[2][mxn];
bool roll = 0;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> X;
    for(int i = 1;i<=n;i++){
        cin>>A[i];
    }
    for(int i = 1;i<=n;i++)cin>>C[i];
    for(int i = 0;i<m;i++){
        int k;
        cin>>k;
        X.push_back(k);
    }
    int used = 0;
    sort(X.rbegin(),X.rend());
    fill(dp[roll],dp[roll]+mxn,inf);
    dp[roll][0] = 0;
    for(int i = 1;i<=n;i++){
        roll ^= 1;
        fill(dp[roll],dp[roll]+mxn,inf);
        if(X.back() == i){
            int pt = i;
            ll small = inf;
            for(int j = used+1;j<mxn;j++){
                while(pt>0&&i-pt<j){
                    small = min(small,C[pt]);
                    pt--;
                }
                dp[roll][j] = dp[roll^1][j-1]+A[i]+small;
            }
            X.pop_back();
            used++;
        }
        else{
            for(int j = used;j<mxn;j++)dp[roll][j] = dp[roll^1][j];
            int pt = i;
            ll small = inf;
            for(int j = used+1;j<mxn;j++){
                while(pt>0&&i-pt<j){
                    small = min(small,C[pt]);
                    pt--;
                }
                dp[roll][j] = min(dp[roll][j],dp[roll^1][j-1]+A[i]+small);
            }
        }
    }
    cout<<*min_element(dp[roll],dp[roll]+mxn);
}