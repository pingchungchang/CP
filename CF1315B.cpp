#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
const int mxn = 1e5+10;
ll a,b,n;
string s;
ll f(int k){
    ll total = 0;
    char now = s[k];
    for(int i = k;i<s.size()-1;i++){
        if(now == s[i])continue;
        else{
            if(now == 'A')total += a;
            else total += b;
            now = s[i];
        }
    }
    if(now == 'A')total += a;
    else total += b;
    return total;
}
void solve(){
    ll p;
    cin>>a>>b>>p;
    cin>>s;
    int l = 0,r = s.size()-1;
    while(l != r){
        int mid = (l+r)>>1;
        if(f(mid)>p)l = mid+1;
        else r = mid;
    }
    cout<<l+1<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}