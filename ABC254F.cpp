#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>seg1,seg2;

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    while(b != 0){
        a %= b;
        swap(a,b);
    }
    return a;
}

void maketree(ll p,ll v,ll now,ll l,ll r,ll t){
    if(l == r){
        if(t == 1)seg1[now] = v;
        else seg2[now] = v;
        return;
    }
    ll mid = (l+r)/2;
    if(mid>=p)maketree(p,v,now*2+1,l,mid,t);
    else maketree(p,v,now*2+2,mid+1,r,t);
    seg1[now] = gcd(seg1[now*2+1],seg1[now*2+2]);
    seg2[now] = gcd(seg2[now*2+1],seg2[now*2+2]);
    return;
}
ll getval(ll now,ll l,ll r,ll s,ll e,ll t){
    if(s<=l&&e>=r){
        if(t == 1)return seg1[now];
        else return seg2[now];
    }
    ll mid = (l+r)/2;
    if(mid>=e)return getval(now*2+1,l,mid,s,e,t);
    else if(mid<s)return getval(now*2+2,mid+1,r,s,e,t);
    else return gcd(getval(now*2+1,l,mid,s,e,t),getval(now*2+2,mid+1,r,s,e,t));
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,q;
    cin>>n>>q;
    seg1 = vector<ll>(n*4,0LL);
    seg2 = vector<ll>(n*4,0LL);
    vector<ll>a(n),b(n);
    for(ll i = 0;i<n;i++){
        cin>>a[i];
    }
    for(ll i = 0;i<n;++i)cin>>b[i];
    for(ll i = 1;i<n;i++){
        maketree(i,abs(a[i]-a[i-1]),0,0,n-1,1);
        maketree(i,abs(b[i]-b[i-1]),0,0,n-1,2);
    }
    for(ll i = 0;i<q;i++){
        ll h1,h2,w1,w2;
        cin>>h1>>h2>>w1>>w2;
        h1--,h2--,w1--,w2--;
        ll G = a[h1]+b[w1];
        if(w1 != w2){
            G = gcd(G,getval(0,0,n-1,w1+1,w2,2));
        }
        if(h1 != h2){
            G = gcd(G,getval(0,0,n-1,h1+1,h2,1));
        }
        cout<<G<<'\n';
    }
}
