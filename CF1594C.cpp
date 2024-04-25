#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(ll asd=0;asd<t;asd++){
        ll n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        ll done =0;
        for(ll i =0;i<n;i++){
            if(s[i]!=c)break;
            if(s[i] == c&&i == n-1){
                cout<<0<<'\n';
                done = 1;
                break;
            }
        }
        if(done)continue;
        for(ll i = n/2;i<n;i++){
            if(2*(1+i)<=n)continue;
            if(s[i] == c){
                cout<<1<<'\n'<<i+1<<'\n';
                done = 1;
                break;
            }
        }
        if(done)continue;
        cout<<2<<'\n'<<n-1<<' '<<n<<'\n';
    }
}
