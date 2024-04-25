#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cout<<"ouob\n";
    cout.flush();
    cin>>n;
    ll l = 1,r = n;
    while(l != r){
        ll mid = (l+r)/2;
        cout<<"? "<<l<<' '<<r<<'\n';cout.flush();
        ll k;
        cin>>k;
        if(k<0)l = mid+1;
        else r = mid;
    }
    cout<<"! "<<l<<'\n';
    cout.flush();
}
