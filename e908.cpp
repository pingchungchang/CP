#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string days[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    unordered_map<string,ll> m;
    for(ll i =0;i<7;i++){
        m[days[i]] = i;
    }
    string s;
    ll n;
    cin>>s>>n;
    cout<<days[(m[s]+n)%7];
}
