#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll arr[100001];
ll ans;

void conquer(ll s,ll e){
    ll mid = (s+e)/2;
    ll f[mid-s+1]={0};
    for(ll i =s;i<=mid;i++){
        f[i-s] = arr[i];

    }
    ll p1 = 0,p2 = mid+1;
    for(ll i =s;i<=e;i++){
        if(p2 > e){
            ans += e-mid;
            arr[i] = f[p1];
            p1++;
        }
        else if(p1 >= mid-s+1){
            break;
        }
        else if(f[p1]>arr[p2]){
            arr[i] = arr[p2];
            p2++;
        }
        else{
            arr[i] = f[p1];
            ans += p2-mid-1;
            p1++;
        }
    }
    //delete((ll*)f);
    return;
}

void divide(ll s,ll e){
    if(s==e)return;
    else if(s == e-1){
        if(arr[s]>arr[e]){
            ans++;
            ll k = arr[e];
            arr[e] = arr[s];
            arr[s] = k;
        }
        return;
    }
    ll mid = (s+e)/2;
    divide(s,mid);
    divide(mid+1,e);
    conquer(s,e);
    return;
}
int main(){
    ll t =0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    while(cin>>n){
        memset(arr,0LL,sizeof(arr));
        t++;
        if(n==0)return 0;
        for(ll i =0;i<n;i++){
            cin>>arr[i];
        }
        ans = 0;
        divide(0,n-1);
        cout<<"Case #"<<t<<": ";
        cout<<ans<<'\n';
    }
}
