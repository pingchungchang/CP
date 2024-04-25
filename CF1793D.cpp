#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

bool in(ll a,ll b,ll c){
    if(a<=b&&b<=c&&a<=c)return true;
    return false;
}
main(){
    int n;
    cin>>n;
    int arr[n+1],brr[n+1];
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        arr[k] = i;
    }
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        brr[k] = i;
    }
    arr[n+1] = 0;brr[n+1] = n+1;
    ll l = min(arr[1],brr[1]),r = max(arr[1],brr[1]);
    ll ans = 0;
    ans += (n-r)*(n-r+1)/2+l*(l-1)/2+(r-l-1)*(r-l)/2;
    // cout<<ans<<endl<<endl;return 0;
    for(int i = 2;i<=n+1;i++){
        int tl = min(arr[i],brr[i]),tr = max(arr[i],brr[i]);
        if(in(l,tl,r)||in(l,tr,r)){
            l = min(tl,l);
            r = max(tr,r);
            continue;
        }
        if(in(tl,tr,l)){
            ans += (n-r+1)*(l-tr);
        }
        else if(in(r,tl,tr)){
            ans += (tl-r)*l;
        }
        else{
            ans += (tr-r)*(l-tl);
        }
        // cout<<i<<":"<<l<<' '<<r<<' '<<tl<<' '<<tr<<' '<<ans<<'\n';
        l = min(tl,l);
        r = max(tr,r);
    }
    cout<<ans;
}