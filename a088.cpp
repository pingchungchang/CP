#include <bits/stdc++.h>
using namespace std;



#define ll long long
int n;
int x = 0;
void solve(){
    ll arr[n];
    for(int i = 0;i<n;i++)cin>>arr[i];
    ll ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            ll tmp = 1;
            for(int k = i;k<=j;k++){
                tmp *= arr[k];
            }
            ans = max(ans,tmp);
        }
    }
    cout<<"Case #"<<x<<": The maximum product is "<<ans<<".\n\n";
}
int main(){
    while(cin>>n){
        if(n<0)return 0;
        x++;
        solve();
    }
}
