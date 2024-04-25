#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n,x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;
    if(x1>n/2)x1 = n/2-(x1-n/2)+1;
    if(x2>n/2)x2 = n/2-(x2-n/2)+1;
    if(y1>n/2)y1 = n/2-(y1-n/2)+1;
    if(y2>n/2)y2 = n/2-(y2-n/2)+1;
    x1 = (n/2-x1+1),x2 = (n/2-x2+1),y1 = n/2-y1+1,y2 = n/2-y2+1;
    cout<<abs(max(x1,y1)-max(x2,y2))<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}