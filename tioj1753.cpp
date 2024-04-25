#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 3e5+10;
pll arr[mxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<pll> v;
    for(int i = 1;i<=n;i++){
        cin>>arr[i].fs>>arr[i].sc;
    }
    sort(arr+1,arr+n+1);
    for(int i = 1;i<=n;i++){
        if(v.empty()||v.back().fs != arr[i].fs)v.push_back({arr[i].fs,1});
        else v.back().sc++;
    }
    ll ans = 0,pre = 0;
    for(auto &i:v){
        ans += pre * i.sc;
        pre += i.sc;
    }
    assert(pre == n);
    cout<<ans;
}