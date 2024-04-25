#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    int ans = 0;
    while(a<b){
        a*= c;
        ans++;
    }
    cout<<ans;
}
