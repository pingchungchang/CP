#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    int ans = 0;
    if(c != m)ans++;
    if(c != 1)ans++;
    if(r != 1)ans++;
    if(r != n)ans++;
    cout<<ans;
}