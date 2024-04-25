#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
const ll mxn = 101;
const ll inf = 4e18;
typedef vector<vector<ll>> vvl;


vvl mult(vvl &a,vvl &b){
    vvl re(mxn,vector<ll>(mxn,inf));
    for(int i =0;i<mxn;i++){
        for(int j = 0;j<mxn;j++){
            for(int k = 0;k<mxn;k++){
                re[i][j] = min(re[i][j],a[i][k]+b[k][j]);
            }
        }
    }
    return re;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    vvl a(mxn,vector<ll>(mxn,inf));
    auto b= a;
    while(m--){
        ll x,y,c;
        cin>>x>>y>>c;
        a[x][y] = min(a[x][y],c);
        b[x][y] = min(b[x][y],c);
    }
    k--;
    while(k){
        if(k&1)a = mult(a,b);
        b = mult(b,b);
        k>>=1;
    }
    cout<<(a[1][n]>=inf?-1:a[1][n]);    
}