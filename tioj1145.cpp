#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimze("O3")
#pragma GCC target("avx2")

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
vector<pll> v;
const int mxn = 101;
ll dp[mxn][mxn];
const ll inf = 1e18;

ll calc(ll a,ll b,ll t){
    if(t == 1)return a*b;
    else if(t == 2)return a+b;
    else return a-b;
}
void f(ll l,ll r){
    if(l == r){
        dp[l][r] = v[l].fs;
        return;
    }
    if(dp[l][r] != -inf)return;
    for(int i = l;i<r;i++){
        f(l,i);
        f(i+1,r);
        dp[l][r] = max(dp[l][r],calc(dp[l][i],dp[i+1][r],v[i].sc));
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    string num;
    for(auto &i:dp)for(auto &j:i)j = -inf;
    for(auto &i:s){
        if(i>='0'&&i<='9')num += i;
        else{
            int cal;
            if(i == '*')cal = 1;
            else if(i == '+')cal = 2;
            else cal = 0;
            v.push_back({stoll(num),cal});
            num = "";
        }
    }
    v.push_back({stoll(num),-1});
    // for(auto &i:v)cout<<i.fs<<' '<<i.sc<<',';cout<<'\n';
    f(0,v.size()-1);
    cout<<dp[0][v.size()-1];
    // for(int i = 0;i<v.size();i++){
    //     for(int j= 0;j<v.size();j++)cout<<dp[i][j]<<' ';cout<<'\n';
    // }
}