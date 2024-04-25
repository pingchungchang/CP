#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i =0;i<n;i++)cin>>arr[i];
    if(n==1){
        cout<<"0\n";
        return 0;
    }
    ll ans[n] = {0};
    ll last =0;
    ll times = 0;
    if(arr[0]>arr[1]){
        last = -1;
        times++;
        ans[0]=1;
    }
    for(ll i =1;i<n-1;i++){
        if(last == 0){
            if((arr[i+1]-arr[i])<0){
                last = -1;
                ans[i] = 1;
                times++;
            }

            continue;
        }
        if(last*(arr[i+1]-arr[i])<0){
            ans[i]=1;
            last = -last;
            times++;
        }
    }
    if(times&1){
        ans[n-1] = 1;
    }
    for(ll i=0;i<n;i++){
        cout<<ans[i];
        if(i != n-1)cout<<' ';
    }
}
