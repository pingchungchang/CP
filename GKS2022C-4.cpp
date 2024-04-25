#include <bits/stdc++.h>
using namespace std;
#define ll long long


int tt = 0;
const ll mod = 1e9+7;
ll pw(ll a,ll b){
    ll ans = 1LL;
    while(b != 0){
        if((b&1))ans = ans*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return ans;
}
ll inverse(ll now){
    return pw(now,mod-2);
}
int n;string s;
bool ispal(string &ss){
    for(int i = 0;i<ss.size()/2;i++){
        if(ss[i] != ss[ss.size()-1-i])return false;
    }
    return true;
}
ll f(vector<int>&v){
    bitset<9> used = {};
    for(int i = 0;i<n;i++)used[i] = true;
    ll returns = 0;
    string tmp;
    for(int i = 0;i<v.size();i++){
        used[v[i]] = false;
        tmp = "";
        for(int j = 0;j<n;j++)if(used[j])tmp += s[j];
        //cout<<tmp<<' '<<ispal(tmp)<<endl;
        if(ispal(tmp))returns++;
    }
    return returns;
}
void solve(){
    tt++;
    cin>>n;
    cin>>s;
    if(n>8)return;
    vector<int> v(n);
    for(int i = 0;i<n;i++)v[i] = i;
    ll ans = 0;
    ans += f(v);
    while(next_permutation(v.begin(),v.end())){
        ans += f(v);
    }
    ll fac = 1LL;
    for(ll i = 2;i<=n;i++)fac = fac*i%mod;
    cout<<"Case #"<<tt<<": "<<ans*inverse(fac)%mod<<'\n';
    //cout<<ans<<endl<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
