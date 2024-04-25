#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<int> v;
vector<int> suff;
vector<int> ans;
void f(ll r,ll ones,ll val){
    val += suff[r];
    //cout<<r<<' '<<ones<<' '<<val<<endl;
    if(r == 0){
        if(ones == 1)ans[r] = 1;
        else ans[r] = 0;
        return;
    }
    if(val == r+1){
        ans[r] = 1;
        if(r-1>=0&&ones != 1)suff[r-1]--;
        if(r-ones>=0)suff[r-ones]++;
        ones--;
    }
    else{
        ans[r] = 0;
        if(r-1>=0)suff[r-1]--;
        if(r-ones>=0)suff[r-ones]++;
    }
    f(r-1,ones,val);
}
void solve(){
    int n;
    cin>>n;
    suff = vector<int>(n);
    v = vector<int>(n);
    ll total = 0;
    for(int i = 0;i<n;i++){
        cin>>v[i];
        total += v[i];
    }
    for(ll i = n-2;i>=0;i--){

    }
    ans = vector<int>(n,-1);
    int ones = total/n;
    suff[n-1] = v[n-1];
    for(int i = n-2;i>=0;i--)suff[i] = v[i]-v[i+1];
    f(n-1,ones,0LL);
    for(auto i:ans)cout<<i<<' ';cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
