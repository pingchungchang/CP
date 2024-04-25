#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
int n;
const int mxn = 1e4+10;

struct point{
    ll x,y;
    point(){x = 0,y = 0;}
    point(ll a,ll b){x = a,y = b;}
    point operator+(point b){
        return point(x+b.x,y+b.y);
    }
    point operator-(point b){
        return point(x-b.x,y-b.y);
    }
    ll operator*(point b){return x*b.x+y*b.y;}
    ll operator^(point b){return x*b.y-y*b.x;}
    bool operator<(point b)const{
        if(x != b.x)return x<b.x;
        else return y<b.y;
    }
    bool operator==(point b){
        return x==b.x&&y==b.y;
    }
    bool operator!=(point b){
        return !((*this)==b);
    }
};

ostream &operator<<(ostream& out,point p){
    out<<p.x<<' '<<p.y;
    return out;
}

ld len(point a){
    return sqrt(a.x*a.x+a.y*a.y);
}

ll area(point a,point b,point c){
    return abs((a-b)^(c-b));
}


void solve(){
    point arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
    }
    sort(arr,arr+n);
    // for(auto &i:arr)cout<<i.x<<' '<<i.y<<',';cout<<endl;
    vector<point> up,down;
    for(auto &now:arr){
        if(up.empty()){
            up.push_back(now);
            continue;
        }
        while(up.size()>=2&&((now-up[up.size()-2])^(up.back()-up[up.size()-2]))<=0)up.pop_back();
        up.push_back(now);
    }
    reverse(arr,arr+n);
    for(auto &now:arr){
        if(down.empty()){
            down.push_back(now);
            continue;
        }
        while(down.size()>=2&&((now-down[down.size()-2])^(down.back()-down[down.size()-2]))<=0)down.pop_back();
        down.push_back(now);
    }
    if(!down.empty())down.pop_back();
    if(!up.empty())up.pop_back();
    for(auto &i:down)up.push_back(i);
    int s= up.size();
    for(int i = 0;i<=s;i++)up.push_back(up[i]);
    // for(auto &i:up)cout<<i.x<<' '<<i.y<<',';cout<<endl;
    // cout<<endl<<endl;
    ld ans = 1e18;
    int p1=0,p2 = 0,p3 = 0;
    for(int i = 1;i<up.size()/2+1;i++){
        while(p1<up.size()-1&&area(up[p1],up[i],up[i-1])<=area(up[p1+1],up[i],up[i-1]))p1++;
        auto v0 = up[i]-up[i-1];
        while(p2<up.size()-1&&(v0*(up[p2]-up[i-1]))<(v0*(up[p2+1]-up[i-1])))p2++;
        p3 = p1;
        v0 = up[i-1]-up[i];
        // while(up[p3] != up[i-1]&&p3<=n*2&&)
        while(up[p3] != up[i-1]&&p3<up.size()-1&&(v0*(up[p3]-up[i]))<(v0*(up[p3+1]-up[i])))p3++;
        point h = up[i]-up[i-1];
        swap(h.x,h.y);
        h.x = -h.x;
        ld coef = (up[p2]-up[p3])*h/len(h)/len(h);
        // cout<<(up[p2]-up[p3])<<' '<<h<<' '<<len(h)<<' '<<coef<<endl;
        pair<ld,ld> tmp;
        tmp.fs = h.x*coef,tmp.sc = h.y*coef;
        // h.x *= coef;h.y *= coef;
        // ld width = sqrt(len(up[p2]-up[p3])*len(up[p2]-up[p3])-len(h)*len(h)/coef/coef);
        auto tt = up[p2]-up[p3];
        tmp.fs = tt.x-tmp.fs,tmp.sc = tt.y-tmp.sc;
        ld width = sqrt(tmp.fs*tmp.fs+tmp.sc*tmp.sc);
        // ld width = len((up[p2]-up[p3])-h);
        ld height = area(up[i],up[i-1],up[p1])/len(up[i]-up[i-1]);
        ans = min(ans,(width+height)*2);
        // cout<<up[i-1]<<','<<up[i]<<','<<up[p1]<<','<<up[p2]<<','<<up[p3]<<' '<<width<<' '<<h<<' '<<len(up[i]-up[i-1])<<endl;
    }
    cout<<fixed<<setprecision(20)<<ans<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n&&n)solve();
}