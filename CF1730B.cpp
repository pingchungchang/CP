#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
const int mxn = 1e5+10;
ll x[mxn],t[mxn];
int n;

bool isl(ld k){
    ld l = 0,r = 0;
    for(int i = 0;i<n;i++){
        if(x[i]>=k)r = max(r,x[i]-k+t[i]);
        else l = max(l,k-x[i]+t[i]);
    }
    return l>r;
}
void solve(){
    cin>>n;
    for(int i = 0;i<n;i++)cin>>x[i];
    for(int i = 0;i<n;i++)cin>>t[i];
    ld l = 0,r = 1e8;
    for(int i = 0;i<100;i++){
        ld mid = (l+r)/2;
        if(isl(mid))r = mid;
        else l = mid;
    }
    cout<<fixed<<setprecision(10)<<l<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}