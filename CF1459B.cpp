#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    ll x,y,t;
    char dir;
    node(){}
    node(ll a,ll b,ll c,char d){
        dir = d;
        x = a,y = b,t = c;
    }
};
int main(){
    ll n;
    cin>>n;
    ll k = n%2;
    ll ans = 0;
    for(ll i = -1000;i<=1000;i++){
        for(ll j = -1000;j<=1000;j++){
            ll a = i,b = j;
            ll x = (a+(n+k)/2)/2,y = (b+(n-k)/2)/2,z = ((n+k)/2-a)/2,w = ((n-k)/2-b)/2;
            if(x-z == a&&y-w == b&&x+y+z+w == n&&x>=0&&y>=0&&z>=0&&w>=0&&abs(x+z-y-w)<=abs(k)){
                ans++;
            }
            else{
                k = -k;
                ll x = (a+(n+k)/2)/2,y = (b+(n-k)/2)/2,z = ((n+k)/2-a)/2,w = ((n-k)/2-b)/2;
                if(x-z == a&&y-w == b&&x+y+z+w == n&&x>=0&&y>=0&&z>=0&&w>=0&&abs(x+z-y-w)<=abs(k)){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
}
