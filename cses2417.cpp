#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

const int mxn = 1e6+10;
int cnt[mxn];
int lpf[mxn];
int main(){
    for(int i = 2;i<mxn;i++){
        if(!lpf[i]){
            for(int j = i;j<mxn;j+=i)lpf[j] = i;
        }
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    long long ans = 0;
    for(int i = 0;i<n;i++){
        int r;
        cin>>r;
        vector<int> v;
        int now= r;
        while(now != 1){
            v.push_back(lpf[now]);
            now/=lpf[now];
        }
        ans += i;
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        // for(auto &j:v)cout<<j<<",";
        for(int j= 1;j<(1<<v.size());j++){
            int c = 0;
            int x = 1;
            for(int k = 0;k<v.size();k++){
                if((1<<k)&j){
                    x *= v[k];
                    c++;
                }
            }
            if(c&1)ans -= cnt[x];
            else ans += cnt[x];
        }
        for(int j= 1;j<(1<<v.size());j++){
            int x = 1;
            for(int k =0;k<v.size();k++){
                if((1<<k)&j)x *= v[k];
            }
            cnt[x]++;
        }
        // for(int i = 1;i<=20;i++)cout<<cnt[i]<<' ';cout<<ans<<'\n';
    }
    cout<<ans;
}