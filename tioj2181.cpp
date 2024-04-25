#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1010;
pii dp[mxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int w,n;
    cin>>w>>n;
    pii arr[n];
    for(auto &i:arr){
        cin>>i.fs>>i.sc;
    }
    for(int i = 0;i<n;i++){
        for(int j = w;j>=arr[i].sc;j--){
            pii tmp = {arr[i].fs+dp[j-arr[i].sc].fs,dp[j-arr[i].sc].sc-arr[i].sc};
            dp[j] = max(tmp,dp[j]);
        }
    }
    cout<<dp[w].fs<<' '<<-dp[w].sc;
}
