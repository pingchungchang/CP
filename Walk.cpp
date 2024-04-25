#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<vector<ll>> mult(vector<vector<ll>> &x,vector<vector<ll>> &v){
    vector<vector<ll>> tmp(x.size(),vector<ll>(x.size(),0));
    int n = x.size();
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            for(int k =0;k<n;k++){
                tmp[i][j]+= x[i][k]*v[k][j];
                tmp[i][j] = tmp[i][j]%(ll)(1e9+7);
            }
        }
    }
    return tmp;
}
int main(){
  	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll t;
    cin>>n>>t;
    vector<vector<ll>> v(n,vector<ll>(n,0));
    vector<vector<ll>> ans(n,vector<ll>(n,0));
    for(int i =0;i<n;i++){
        ans[i][i]=1;
        for(int j =0;j<n;j++){
            int a;
            cin>>a;
            v[i][j] = a;
        }
    }
    while(t>0){
        if(t&1){
            ans = mult(ans,v);
        }
        v = mult(v,v);
        t>>=1;
    }
    /*for(int i =0;i<n;i++){
        for(int j =0;j<n;j++)cout<<ans[i][j]<<' ';
        cout<<endl;
    }*/
    ll fin = 0;
    for(int i =0;i<n;i++)for(int j =0;j<n;j++)fin = (fin+ans[i][j])%1000000007;
    cout<<fin;
}
