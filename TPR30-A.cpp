#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,m,x;
    cin>>n>>m>>x;
    cout<<(n+x-1)/x*((m+x-1)/x);
}