#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    map<int,int> mp;
    int cnt = 0;
    long long total = 0;
    while(n--){
        int k;
        cin>>k;
        total += abs(k);
        mp[abs(k)]++;
        if(k<0)cnt++;
    }
    if(cnt&1){
        cout<<total-mp.begin()->first*2<<'\n';
    }
    else cout<<total<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}