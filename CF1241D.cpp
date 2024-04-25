#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> all;
    for(int i = 0;i<n;i++){
        cin>>v[i];
        all.push_back(v[i]);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    vector<int>l(all.size(),1e9);
    vector<int>r(all.size(),-1e9);
    for(int i= 0;i<n;i++){
        v[i] = lower_bound(all.begin(),all.end(),v[i])-all.begin();
        l[v[i]] = min(l[v[i]],i);
        r[v[i]] = max(r[v[i]],i);
    }
    int ans = all.size()-1;
    vector<int>dp(all.size(),1);
    for(int i = 1;i<all.size();i++){
        if(l[i]>r[i-1]){
            dp[i] = dp[i-1]+1;
        }
        else dp[i] = 1;
        ans = min(ans,(int)all.size()-dp[i]);
    }
    cout<<ans<<'\n';
    return;

}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
