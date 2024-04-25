#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int cnt = 0;
    int mt = INT_MAX;
    vector<pair<int,int>> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i].first;
        v[i].second = 0;
        int tmp = v[i].first;
        while(tmp%2 == 0){
            tmp>>=1;
            v[i].second++;
        }
        mt = min(mt,v[i].second);
        if(v[i].second != 0)cnt++;
    }
    //for(auto i:v)cout<<i.first<<' '<<i.second<<',';
    if(mt == 0)cout<<cnt<<'\n';
    else cout<<cnt+mt-1<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
