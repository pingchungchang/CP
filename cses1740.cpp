#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define _all(T) T.begin(),T.end()

struct point{
    ll x,y;
    point(){}
    point(ll a,ll b):x(a),y(b){}
    point operator+(point b){return point(x+b.x,y+b.y);}
    point operator-(point b){return point(x-b.x,y-b.y);}
    bool operator<(point b)const{return x == b.x?y<b.y:x<b.x;}
};

istream &operator>>(istream &in,point &p){
    in>>p.x>>p.y;
    return in;
}

struct event{
    int tp;
    point pos;
    ll st;
    event(){}
    event(int tt,point pp):pos(pp),tp(tt){}
    bool operator<(event b)const{
        return st<b.st;
    }
};

const ll mxn = 1e5+10;
ll n;
vector<event> sweep;
vector<ll> all;
ll bit[mxn*8];
void modify(int p,int v){
    for(;p<mxn*8;p+=p&-p)bit[p] += v;
    return;
}
ll getval(int s,int e){
    ll re =0;
    for(;e>0;e-= e&-e)re += bit[e];
    s--;
    for(;s>0;s-= s&-s)re -= bit[s];
    return re;
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i =0;i<n;i++){
        point s,e;
        cin>>s>>e;
        // cout<<s.x<<' '<<s.y<<' '<<e.x<<' '<<e.y<<endl;
        all.push_back(s.y);
        all.push_back(e.y);
        if(s.x == e.x){
            sweep.push_back(event());
            sweep.back().pos = point(s.y,e.y);
            sweep.back().st = s.x;
            sweep.back().tp = 0;
        }
        else{
            event tmp;
            tmp.st = s.x;
            tmp.pos = point(s.y,s.y);
            tmp.tp = 1;
            sweep.push_back(tmp);
            tmp.st = e.x;
            tmp.tp = -1;
            sweep.push_back(tmp);
        }
    }
    sort(_all(all));
    all.erase(unique(_all(all)),all.end());
    sort(sweep.begin(),sweep.end());
    ll ans = 0;
    // for(auto &i:sweep)cout<<i.tp<<','<<i.pos.x<<' '<<i.pos.y<<endl;
    for(auto &i:sweep){
        if(i.tp == 0){
            ll l = lower_bound(_all(all),i.pos.x)-all.begin()+1;
            ll r = lower_bound(_all(all),i.pos.y)-all.begin()+1;
            ans += getval(l,r);
        }
        else{
            ll p = lower_bound(_all(all),i.pos.x)-all.begin()+1;
            modify(p,i.tp);
        }
    }
    cout<<ans;
}