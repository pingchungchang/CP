#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> arr[m];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            int k;
            cin>>k;
            arr[j].push_back(k);
        }
    }
    long long ans = 0;
    for(auto &now:arr){
        long long pref = 0;
        sort(now.begin(),now.end());
        for(int j = 0;j<n;j++){
            ans += 1LL*j*now[j]-pref;
            pref += now[j];
        }
    }
    cout<<ans<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}