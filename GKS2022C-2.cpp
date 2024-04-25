#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tt = 0;
void solve(){
    ll n,x,y;
    tt++;
    cin>>n>>x>>y;
    if(n*(n+1)/2%(x+y) != 0){
        cout<<"Case #"<<tt<<": IMPOSSIBLE\n";
        return;
    }
    vector<ll>ans;
    ll tar = n*(n+1)/2/(x+y)*x;
    for(ll i = n;i>=1;i--){
        if(tar>=i){
            ans.push_back(i);
            tar -= i;
        }
    }
    cout<<"Case #"<<tt<<": POSSIBLE\n";
    cout<<ans.size()<<'\n';
    for(auto i:ans)cout<<i<<' ';cout<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
