#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,-unroll-loops")

#define ll __int128_t
#define fs first
#define sc second
#define pll pair<ll,ll>
#define ld long double
const int mxn = 5e4+10;
pll arr[mxn];
int n;
long double calc(pll a,pll b){
    ld da = a.fs-b.fs,db = a.sc-b.sc;
    return sqrt(da*da+db*db);
}
void solve(){
    for(int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr[i].fs = a,arr[i].sc = b;
    }
    sort(arr,arr+n);
    ld ans = 1e18;
    for(int i= 0;i<n;i++){
        for(int j = i+1;(arr[i].fs-arr[j].fs)*(arr[i].fs-arr[j].fs)<ans*ans&&j<n;j++){
            ans = min(ans,calc(arr[i],arr[j]));
        }
    }
    cout<<fixed<<setprecision(6)<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n)solve();
}