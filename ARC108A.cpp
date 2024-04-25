#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=sqrt(m);i++){
        if(m%i == 0){
            if(i+m/i == n){
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}
