#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    if(m == 1){
        cout<<n-1<<'\n';return 0;
    }
    cout<<n*(m-1)<<'\n';
    return 0;
}