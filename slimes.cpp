#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll arr[n+1][n+1];
    ll slimes[n+1];
    slimes[0] = 0;
    for(ll i =1;i<=n;i++){
        cin>>slimes[i];
        slimes[i] += slimes[i-1];
        arr[i][i] = 0;
    }
    for(ll len=2;len<=n;len++){
        for(ll j =1;j+len-1<=n;j++){
            arr[j][j+len-1] = LONG_LONG_MAX;
            for(ll k = j;k<j+len-1;k++){
                //cout<<j<<' '<<k<<' '<<len<<endl;
                arr[j][j+len-1] = min(arr[j][j+len-1],arr[j][k]+arr[k+1][j+len-1]+slimes[j+len-1]-slimes[j-1]);
            }
        }
    }
    cout<<arr[1][n];
}
