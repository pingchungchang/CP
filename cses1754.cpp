#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n;
    cin>>n;
    for(ll asd=0;asd<n;asd++){
        ll a,b;
        cin>>a>>b;
        if((a+b)%3!=0){
            cout<<"NO";
        }
        else{
            if(a+b<=3*a&&a+b<=3*b)cout<<"YES";
            else cout<<"NO";
        }
        if(asd!= n-1)cout<<'\n';
    }
}
