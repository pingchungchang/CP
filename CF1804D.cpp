#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int ans1 = 0,ans2 = 0;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        int cnt = 0;
        for(auto &j:s)if(j == '1')cnt++;
        int same = 0;
        for(int j = 1;j<m;j++){
            if(s[j] == s[j-1]&&s[j] == '1'){
                same++;
                j++;
            }
        }
        // cout<<cnt<<":"<<same<<endl;
        // cout<<cnt-same<<',';
        ans1 += (cnt-min(same,m/4));
        same = 0;
        for(int j = 1;j<m;j++){
            if(s[j] != s[j-1]){
                same++;
                j++;
            }
            else if(s[j] == s[j-1]&&s[j] == '0'){
                same++;
                j++;
            }
        }
        same = max(0,m/4-same);
        int rest = cnt-same*2;
        ans2 += rest+same;
    }
    cout<<ans1<<' '<<ans2<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    while(t--)solve();
}
/*

ans = n/2-cnt1+cnt(same)
*/
