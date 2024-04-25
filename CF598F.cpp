#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fs first
#define sc second

const ld eps = 1e-7;

struct point{
    ld x,y;
    point(ld a,ld b){
        x = a,y = b;
    }
    point(){x = y = 0;}
    point operator+(point b){
        return point(x+b.x,y+b.y);
    }
    point operator-(point b){
        return point(x-b.x,y-b.y);
    }
    ld operator*(point b){
        return x*b.x+y*b.y;
    }
    ld operator^(point b){
        return x*b.y-y*b.x;
    }
    bool operator<(point b)const{
        if(x != b.x)return x<b.x;
        else return y<b.y;
    }
};

const int mxn = 1010;
int n;
point pol[mxn];

ostream& operator<<(ostream& out,point p){
    out<<p.x<<' '<<p.y;
    return out;
}

ld len(point k){
    return sqrt(k.x*k.x+k.y*k.y);
}

void solve(){
    point s,e;
    cin>>s.x>>s.y>>e.x>>e.y;
    ld ans =0;
    vector<point>pts;
    for(int i = 1;i<=n;i++){
        point a = pol[i],b = pol[i-1];
        int flag = 0;
        if(abs((s-a)^(e-a))<=eps){
            pts.push_back(a);
            flag++;
        }
        if(abs((s-b)^(e-b)) <= eps){
            pts.push_back(b);
            flag++;
        }
        if(flag==2){
            ans += len(a-b);
            continue;
        }
        else if(flag){
            pts.pop_back();
            continue;
        }
        if(abs((e-s)^(b-a))<=eps)continue;
        // cout<<i<<":"<<a.x<<' '<<a.y<<' '<<b.x<<' '<<b.y<<endl;
        if(((e-s)^(b-s))*((e-s)^(a-s))>=0)continue;
        point d1 = e-s;
        point d2 = b-a;
        ld det = d1^d2;
        det = -det;
        ld da = ((a.x-s.x)*-d2.y+d2.x*(a.y-s.y));
        ld db = (d1.x*(a.y-s.y)-d1.y*(a.x-s.x));
        pts.push_back(point(da/det,db/det));
    }
    for(int i = 0;i<n;i++){
        if((abs(pol[i]-s)^(pol[i]-e))<=eps)pts.push_back(pol[i]);
    }
    sort(pts.begin(),pts.end());
    for(int i = 1;i<pts.size();i+=2){
        cout<<pts[i-1]<<' '<<pts[i]<<',';
        ans += len(pts[i]-pts[i-1]);
    }
    cout<<fixed<<setprecision(20)<<ans<<'\n';
    // cout<<endl<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>n>>q;
    for(int i = 0;i<n;i++)cin>>pol[i].x>>pol[i].y;
    pol[n] = pol[0];
    while(q--)solve();
}