#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
    int n;
    cin>>n;
    ll arr[n];
    for(auto &i:arr)cin>>i;
    for(int i = 0;i<n-1;i++){
        if(arr[i]<-arr[i]){
            arr[i] = -arr[i];
            arr[i+1] = -arr[i+1];
        }
    }
    ll ans = 0;
    for(auto &i:arr)ans += i;
    ll total = 0;
    ll small = INT_MAX;
    for(auto &i:arr){
        small = min(small,abs(i));
        total += abs(i);
    }
    cout<<max(total-small*2,ans);
}
