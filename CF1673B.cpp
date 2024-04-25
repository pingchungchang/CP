#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> all(27,0);
    vector<vector<int>> dp(n,vector<int>(27,0));
    map<char,int> mp;
    for(auto i:s)all[i-'a']++;
    dp[0][s[0]-'a'] = 1;
    mp[s[0]] = 0;
    for(int i = 1;i<n;i++){
        dp[i] = dp[i-1];
        dp[i][s[i]-'a']++;
        if(mp.count(s[i]) != 0){
            int pre = mp[s[i]];
            vector<int> dif(27,0);
            for(int j = 0;j<27;j++){
                dif[j] = dp[i][j]-dp[pre][j];
            }
            for(int j = 0;j<27;j++){
                if(all[j] != 0&&dif[j] == 0){
                    cout<<"NO\n";
                    return;
                }
            }
        }
        mp[s[i]] = i;
    }
    cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
