#include <bits/stdc++.h>
using namespace std;


#define pii pair<int,int>
#define fs first
#define sc second
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    pii arr[n];
    for(auto &i:arr)cin>>i.fs>>i.sc;
    int cnt[n] = {};
    for(int i = 0;i<n;i++){
        for(int j= i+1;j<n;j++){
            if(abs(arr[i].fs-arr[j].fs)+abs(arr[i].sc-arr[j].sc) <= k){
                cnt[i]++;
                cnt[j]++;
            }
        }
    }
    // for(int i = 0;i<n;i++)cout<<cnt[i];
    for(int i = 0;i<n;i++){
        if(cnt[i] == n-1){
            cout<<"1\n";
            return;
        }
    }
    cout<<"-1\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();

}