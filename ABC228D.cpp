#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 1<<20;
#define pll pair<ll,ll>
#define fs first
#define sc second
#define int ll
ll bit[mxn+1];
ll arr[mxn+1];
void modify(int p,ll v){
    for(;p<=mxn;p+= p&-p)bit[p] += v;
    return;
}
ll getval(ll s,ll e){
    ll re= 0;
    for(;e>0;e -= e&-e)re += bit[e];
    s--;
    for(;s>0;s -= s&-s)re -= bit[s];
    return re;
}

main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fill(arr,arr+mxn+1,-1);
    for(int i = 1;i<=mxn;i++)modify(i,1);
    ll q;
    cin>>q;
    while(q--){
        int t;
        ll x;
        cin>>t>>x;
        if(t == 1){
            ll val = x;
            x %= mxn;
            x++;
            ll l = x,r = mxn;
            while(l != r){
                ll mid = (l+r)>>1;
                if(getval(x,mid)>=1)r = mid;
                else l = mid+1;
            }
            if(getval(l,l) == 0){
                l = 1,r = x-1;
                while(l != r){
                    ll mid = (l+r)>>1;
                    if(getval(1,mid) >= 1)r = mid;
                    else l = mid+1;
                }
            }
            modify(l,-1);
            // cout<<l<<endl;
            arr[l] = val;
        }
        else{
            x %= mxn;
            x++;
            cout<<arr[x]<<'\n';
        }
    }
    return 0;
}