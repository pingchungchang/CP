#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll a,b;
    cin>>a>>b;
    string s = to_string(a);
    if(b&1)s = "5"+s;
    else s = "0"+s;
    if(b/2)s = to_string(b/2)+s;
    cout<<s;
}