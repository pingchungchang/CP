#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll a,b;
    cin>>a>>b;
    ll ans = 0;
    while(a<=b){
        ans ++;
        a*=2;
    }
    cout<<ans;
}
