#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll

struct point{
    ll x,y;
    point(){x = y = 0;}
    point(ll a,ll b):x(a),y(b){}
    point operator+(point b){return point(x+b.x,y+b.y);}
    point operator-(point b){return point(x-b.x,y-b.y);}
    ll operator*(point b){return x*b.x+y*b.y;}
    ll operator^(point b){return x*b.y-y*b.x;}
    bool operator<(point b)const{return x== b.x?y<b.y:x<b.x;}
};

istream & operator>>(istream & in,point &p){
    in>>p.x>>p.y;
    return in;
}

struct line{
    point s,e;
    line(point a,point b):s(a),e(b){}
    line(){}
    bool operator<(line b)const{
        auto tmp = *this;
        if(b.e.x == -1){
            return ((tmp.e-tmp.s)^(b.s-tmp.s))<0?true:false;
        }
        bool flag = false;
        if(tmp.s.x<b.s.x)swap(tmp,b),flag = true;
        return (((tmp.e-tmp.s)^(b.s-tmp.s))<0?true:false)^flag;
    }
};

struct event{
    ll id;
    point pos;
    event(){}
    event(ll ii,point pp):pos(pp),id(ii){}
    bool operator<(event b)const{return pos.x == b.pos.x?(id*b.id<0?id<b.id:id>b.id):pos.x<b.pos.x;}
};

const int mxn = 1e5+10;
ll n;
line arr[mxn];
set<line> st;
vector<event> sweep;
point now(0,0);

main(){
    // freopen("hillwalk.in","r",stdin);
    // freopen("hillwalk.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>arr[i].s>>arr[i].e;
        sweep.push_back(event(i,arr[i].s));
        sweep.push_back(event(-i,arr[i].e));
    }
    sort(sweep.begin(),sweep.end());
    bool flag = false;
    int ans = 0;
    for(auto &i:sweep){
        if(flag)break;
        while(now.x<i.pos.x){
            auto it = st.lower_bound(line(now,point(-1,-1)));
            if(it != st.end()){
                ans++;
                // assert(it->e.x>now.x);
                now = it->e;
            }
            else{
                flag = true;
                break;
            }
        }
        if(i.id<0){
            i.id = -i.id;
            assert(st.erase(line(arr[i.id].s,arr[i.id].e)) == 1);
        }
        else{
            st.insert(line(arr[i.id].s,arr[i.id].e));
        }
    }
    cout<<ans;
}
/*
4
0 0 5 6
1 0 2 1
7 2 8 5
3 0 7 7

*/
