#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;

vector<vector<ll>> mult(vector<vector<ll>> a,vector<vector<ll>> b){
    vector<vector<ll>> re(6,vector<ll>(6,0LL));
    for(int i= 0;i<6;i++){
        for(int j = 0;j<6;j++){
            for(int k = 0;k<6;k++){
                re[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    for(auto &i:re)for(auto &j:i)j %= mod;
    return re;
}
int main(){
    vector<vector<ll>> now(6,vector<ll>(6,0)),tmp(6,vector<ll>(6,0LL));
    for(int i =0;i<6;i++){
        now[i][i] = 1LL;
        tmp[0][i] = 1;
        if(i != 0)tmp[i][i-1] = 1LL;
    }
    long long n;
    cin>>n;
    while(n){
        if(n&1)now = mult(now,tmp);
        n>>=1;
        tmp = mult(tmp,tmp);
    }
    cout<<now[0][0];
}