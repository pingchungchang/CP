#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int n,m;

bool check(int l,int cen){
    int r = cen*2-l;
    if(r-l+1>m)return false;
    if(cen-m/2<0||cen+m/2>=n)return false;
    if(r>=n)return false;
    return true;
}
const int mxn = 2e5+10;
vector<pii> req[mxn*2];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int arr[n+2] = {};
    for(int i = 0;i<n;i++)cin>>arr[i];
    int lp = 0,rp = 0;
    for(int i = 0;i<n;i+=2){
        lp = max(lp,i+1);
        while(lp<n&&!check(i,lp))lp++;
        rp = max(rp,lp);
        while(rp<n&&check(i,rp))rp++;
        req[2*lp-i].push_back({arr[i],-1});
        req[2*rp-i].push_back({arr[i],1});
        // cout<<i<<":"<<lp<<' '<<rp<<endl;
    }
    lp = rp = 1;
    for(int i = 1;i<n;i+=2){
        lp = max(lp,i+1);
        while(lp<n&&!check(i,lp))lp++;
        rp = max(rp,lp);
        while(rp<n&&check(i,rp))rp++;
        req[2*lp-i].push_back({arr[i],-1});
        req[2*rp-i].push_back({arr[i],1});
    }
    int cnt = 0;
    long long ans = 0;
    map<int,int> mp;
    for(int i = 0;i<n+2;i+=2){
        for(auto &j:req[i]){
            ans += (cnt-mp[j.first])*j.second;
            // cout<<i<<":"<<j.first<<' '<<j.second<<' '<<ans<<endl;
        }
        mp[arr[i]]++;
        cnt++;
    }
    for(int i = 1;i<n+2;i+=2){
        for(auto &j:req[i])ans += j.second*(cnt-mp[j.first]);//cout<<i<<":"<<j.first<<' '<<j.second<<' '<<ans<<endl;
        mp[arr[i]]++;
        cnt++;
    }
    cout<<ans;
    return 0;
}
/*
x,x+l,x+l+2,x+l+4,...x+r
*/
