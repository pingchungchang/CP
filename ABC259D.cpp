#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxn = 5050;
int dsu[mxn],sz[mxn];
tuple<ll,ll,ll> arr[mxn];
int root(int k){
    return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
    int ra = root(a),rb = root(b);
    if(ra == rb)return;
    if(sz[ra]<sz[rb])swap(ra,rb);
    dsu[rb] = ra;
    sz[ra] += sz[rb];
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        sz[i] = 1;
        dsu[i] = i;
    }
    ll sx,sy,ex,ey;
    cin>>sx>>sy>>ex>>ey;
    for(int i = 1;i<=n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        arr[i] = make_tuple(a,b,c);
        for(int j = 1;j<i;j++){
            ll xa = get<0>(arr[j]),ya = get<1>(arr[j]),ra = get<2>(arr[j]);
            if((xa-a)*(xa-a)+(ya-b)*(ya-b)<=(ra+c)*(ra+c)&&(xa-a)*(xa-a)+(ya-b)*(ya-b)>=(ra-c)*(ra-c))onion(j,i);
        }
    }
    int pa = -1,pb = -1;
    for(int i = 1;i<=n;i++){
        ll x = get<0>(arr[i]),y = get<1>(arr[i]),r = get<2>(arr[i]);
        if(r*r == (x-sx)*(x-sx)+(y-sy)*(y-sy))pa = i;
        if(r*r == (x-ex)*(x-ex)+(y-ey)*(y-ey))pb = i;
    }
    // cout<<pa<<' '<<pb<<endl;
    if(pa != -1&&pb != -1&&root(pa) == root(pb))cout<<"Yes";
    else cout<<"No";
}