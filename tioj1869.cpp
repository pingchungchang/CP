#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n;
vector<vector<ll>> bit(1045,vector<ll>(1045,0LL));

ll lowbit(ll x){
    return (x&(-x));
}
void changeval(ll x,ll y,ll val){
    while(x<=n){
        ll tmp = y;
        while(tmp<=n){
            bit[x][tmp] += val;
            tmp += lowbit(tmp);
        }
        x += lowbit(x);
    }
    return;
}

ll getval(ll x,ll y){
    ll ans = 0;
    while(x>0){
        ll tmp = y;
        while(tmp>0){
            ans += bit[x][tmp];
            tmp -= lowbit(tmp);
        }
        x -= lowbit(x);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>n;
    while(cin>>t){
        if(t == 0)return 0;
        if(t == 1){
            ll x,y,z;
            cin>>x>>y>>z;
            x++,y++;
            changeval(x,y,z);
        }
        else{
            ll x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            x1++,y1++,x2++,y2++;
            cout<<getval(x2,y2)+getval(x1-1,y1-1)-getval(x1-1,y2)-getval(x2,y1-1)<<'\n';
        }
    }
}
