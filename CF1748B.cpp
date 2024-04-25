#include <bits/stdc++.h>
using namespace std;

void solve(){
    int cnt[10] = {};
    int n;
    string s;
    cin>>n>>s;
    long long ans = 0;
    for(int i = 0;i<n;i++){
        set<char> appear;
        int cnt[10] = {};
        for(int j = i;j<min(n,i+101);j++){
            cnt[s[j]-'0']++;
            appear.insert(s[j]);
            bool flag = true;
            for(int k = 0;k<10;k++){
                if(cnt[k]>appear.size())flag = false;
            }
            if(flag)ans++;
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