#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i= 1;i<=n;i++)cin>>arr[i];
    bool m1[n+1] = {},m2[n+1] = {};
    for(int i = 1;i<=n;i++){
        if(arr[i] != i)m1[i] = true;
        if(arr[i] != n-i+1)m2[i] = true;
    }
    int c1 = 0,c2 = 0;
    bool ainb = true,bina = true;
    for(int i = 1;i<=n;i++){
        if(m1[i])c1++;
        if(m2[i])c2++;
        if(m1[i]&&!m2[i])ainb = false;
        if(!m1[i]&&m2[i])bina = false;
    }
    if(c1 == c2||ainb||bina)cout<<"Tie\n";
    else if(c1>c2)cout<<"Second\n";
    else cout<<"First\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}