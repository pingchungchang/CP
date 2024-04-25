#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fs first
#define sc second
struct point{
    ll x,y;
    point(){x = y = 0;}
    point(ll a,ll b):x(a),y(b){}
    point operator+(point b){return point(x+b.x,y+b.y);}
    point operator-(point b){return point(x-b.x,y-b.y);}
    ll operator*(point b){return x*b.x+y*b.y;}
    bool operator<(point b)const{return x == b.x?y<b.y:x<b.x;}
};
struct node{
    int x,s,e,id;
    node(){}
    bool operator<(node b)const{
        if(x == b.x){
            if(id*b.id<0)return id<b.id;
            else return s<b.s;
        }
        else return x<b.x;
    }
};

const int mxn = 5e4+10;

set<pair<point,int>> st;
point arr[mxn];
vector<node> sweep;
ll n,k;

ll getans(ll a,ll b){
    point dx(0,k/2),dy(k/2,0);
    vector<point> v1 = {arr[a]+dx+dy,arr[a]-dx+dy,arr[a]-dx-dy,arr[a]+dx-dy};
    point cl = v1[0];
    for(auto &i:v1){
        if(((i-arr[b])*(i-arr[b]))<((cl-arr[b])*(cl-arr[b])))cl = i;
    }
    swap(a,b);
    v1 = {arr[a]+dx+dy,arr[a]-dx+dy,arr[a]-dx-dy,arr[a]+dx-dy};
    point cl2 = v1[0];
    for(auto &i:v1){
        if(((i-arr[b])*(i-arr[b]))<((cl2-arr[b])*(cl2-arr[b])))cl2 = i;
    }
    auto re = abs((cl-cl2).x*(cl-cl2).y);
    assert(re>0);
    return re;
}

int main(){
    freopen("squares.in","r",stdin);
    freopen("squares.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i =1;i<=n;i++){
        cin>>arr[i].x>>arr[i].y;
        node tmp;
        tmp.id = i;
        tmp.x = arr[i].x-k/2;
        tmp.s = arr[i].y-k/2;
        tmp.e = arr[i].y+k/2;
        sweep.push_back(tmp);
        tmp.x += k;
        tmp.id = -tmp.id;
        sweep.push_back(tmp);
    }
    bool flag = false;
    point ans(-1,-1);
    sort(sweep.begin(),sweep.end());
    for(auto &i:sweep){
        // cout<<i.id<<":";for(auto &j:st)cout<<j.sc<<' ';cout<<endl;
        if(i.id<0){
            assert(st.erase({point(i.s,i.e),-i.id}) == 1);
            continue;
        }
        auto it = st.lower_bound({point(i.s,i.e),-1});
        if(it != st.end() && i.e>it->fs.x){
            if(ans.x != -1)flag = true;
            else ans = point(it->sc,i.id);
        }
        if(it != st.begin()&&(--it)->fs.y>i.s){
            if(ans.x != -1)flag = true;
            else ans = point(it->sc,i.id);
        }
        st.insert({point(i.s,i.e),i.id});
    }
    // cout<<ans.x<<' '<<ans.y<<endl;
    if(flag)cout<<-1;
    else if(ans.x == -1)cout<<0;
    else cout<<getans(ans.x,ans.y);
}
/*

4 6
0 0
8 4
-2 1
0 7

*/