#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9+7;
const int mxn = 1e5+10;
int n,k;
ll cnt;
bitset<mxn> goneto = {};
vector<vector<int>> v;
ll pw(ll a,ll b){
    ll tmp = 1LL;
    while(b != 0){
        if((b&1) != 0)tmp = tmp*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return tmp;
}
void dfs(ll now){
    goneto[now] = 1;
    cnt++;
    for(auto nxt:v[now]){
        if(goneto[nxt] == false)dfs(nxt);
    }
    return;
}
int main(){
    cin>>n>>k;
    v = vector<vector<int>>(n+1);
    for(int i = 0;i<n-1;i++){
        int a,b,x;
        cin>>a>>b>>x;
        if(x == 0){
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }
    ll ans = pw(n,k);
    for(int i = 1;i<=n;i++){
        if(goneto[i] == false){
            cnt = 0LL;
            dfs(i);
            ans = ans+mod-pw(cnt,k);
            ans %= mod;
        }
    }
    cout<<ans;
}
