#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

vector<ll> segtree;
vector<ll> vv;

void maketree(int pos,ll val,int now,int l,int r){
    if(l == r){
        segtree[now] = val;
        return;
    }
    int mid = (l+r)/2;
    if(mid>=pos){
        maketree(pos,val,now*2+1,l,mid);
    }
    else maketree(pos,val,now*2+2,mid+1,r);
    segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
    return;
}
ll getval(int s,int e,int now,int l,int r){
    if(s == l&&e == r)return segtree[now];
    int mid = (l+r)/2;
    if(mid>=e)return getval(s,e,now*2+1,l,mid);
    else if(mid+1<=s)return getval(s,e,now*2+2,mid+1,r);
    else return max(getval(s,mid,now*2+1,l,mid),getval(mid+1,e,now*2+2,mid+1,r));
}
int main(){
    int n;
    cin>>n;
    vector<ll> v(n*2);
    priority_queue<pll,vector<pll>,less<pll>> pq;
    ll mx = 0;
    for(int i = 0;i<n;i++){
        cin>>v[i];
        v[i+n] = v[i];
        pq.push(make_pair(v[i],i));
    }
    vv = vector<ll>(n*2,-1);
    for(int i = 0;i<n/2;i++){
        vv[pq.top().sc] = 1;
        vv[pq.top().sc+n] = 1;
        mx += pq.top().fs;
        pq.pop();
    }
    segtree = vector<ll>(16*n,INT_MAX);
    for(int i = 1;i<n*2;i++){
        vv[i] = vv[i]+vv[i-1];
    }
    for(int i = 0;i<n*2;i++){
        maketree(i,vv[i],0,0,n*2-1);
    }
    for(int i = 0;i<n;i++){
        if(getval(i,i+n-1,0,0,n*2-1)<=vv[i]){
            cout<<i<<' '<<mx;//<<' '<<getval(i,i+n-1,0,0,n*2-1)<<'\n';
            return 0;
        }
    }
    cout<<"error\n";
    return 0;
}
