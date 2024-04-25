#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
struct mat{
    ll val[2][2];
    mat(){
        memset(val,0,sizeof(val));
    }
    mat(vector<vector<int>> v){
        for(int i = 0;i<2;i++){
            for(int j= 0;j<2;j++){
                val[i][j] = v[i][j];
            }
        }
    }
    ll* operator[](int idx){
        return (ll*)&val[idx];
    }
    mat operator*(mat b){
        mat tmp = mat();
        for(int i = 0;i<2;i++){
            for(int j =0;j<2;j++){
                for(int k = 0;k<2;k++){
                    tmp[i][j] += val[i][k]*b[k][j];
                }
            }
        }
        for(int i = 0;i<2;i++){
            for(int j= 0;j<2;j++)tmp[i][j] %= mod;
        }
        return tmp;
    }
};

mat mult(mat a,mat b){
    mat re = mat();
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            for(int k = 0;k<2;k++)re[i][j] += a[i][k]*b[k][j];
        }
    }
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++)re[i][j] %= mod;
    }
    return re;
}

int main(){
    mat now({{1,0},{0,1}});
    mat tmp({{1,1},{1,0}});
    long long n;
    cin>>n;
    if(n == 0){
        cout<<0;
        return 0;
    }
    n--;
    while(n>0){
        if(n&1)now = now*tmp;
        tmp = tmp*tmp;
        n>>=1;
    }
    cout<<(now[1][0]+now[1][1])%mod;
}