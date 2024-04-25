#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxn = 101;
const ll mod = 1e9+7;
ll buf[mxn][mxn];
ll a[mxn][mxn],b[mxn][mxn];

void mult(ll a[][mxn],ll b[][mxn],ll pos[][mxn]){
    memset(buf,0,sizeof(buf));
    for(int i = 0;i<mxn;i++){
        for(int j = 0;j<mxn;j++){
            for(int k = 0;k<mxn;k++){
                buf[i][j] += a[i][k]*b[k][j]%mod;
                if(buf[i][j]>=mod)buf[i][j] -= mod;
            }
        }
    }
    for(int i = 0;i<mxn;i++){
        for(int j= 0;j<mxn;j++)pos[i][j] = buf[i][j];
    }
    return;
}
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    while(m--){
        int x,y;
        cin>>x>>y;
        b[x][y]++;
        a[x][y]++;
    }
    k--;
    while(k){
        if(k&1)mult(a,b,a);
        mult(b,b,b);
        k>>=1;
    }
    cout<<a[1][n];
}