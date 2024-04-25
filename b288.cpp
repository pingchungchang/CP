#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
const ld eps = 1e-7;

struct point{
    ld x,y;
    point(){x = y = 0;}
    point(ld a,ld b):x(a),y(b){}
    point operator+(point b)const{return point(x+b.x,y+b.y);}
    point operator-(point b)const{return point(x-b.x,y-b.y);}
    ld operator*(point b)const{return x*b.x+y*b.y;}
    ld operator^(point b)const{return x*b.y-y*b.x;}
    bool operator<(point b)const{return x==b.x?y<b.y:x<b.x;}
};

vector<point> up,down;

ld area(point a,point b,point c){return abs((a-b)^(c-b));}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    point arr[n];
    for(auto &i:arr)cin>>i.x>>i.y;
    sort(arr,arr+n);
    for(auto &i:arr){
        if(up.empty()){
            up.push_back(i);
            continue;
        }
        auto now = i;
        while(up.size()>=2&&((now-up[up.size()-2])^(up.back()-up[up.size()-2]))<=eps)up.pop_back();
        up.push_back(now);
    }
    reverse(arr,arr+n);
    for(auto &now:arr){
        if(down.empty()){
            down.push_back(now);
            continue;
        }
        while(down.size()>=2&&((now-down[down.size()-2])^(down.back()-down[down.size()-2]))<=eps)down.pop_back();
        down.push_back(now);
    }
    up.pop_back();down.pop_back();
    for(auto &i:down)up.push_back(i);
    // for(auto &i:up)cout<<i.x<<','<<i.y<<' ';cout<<endl;
    int s= up.size();
    ld ans = 0;
    for(int i = 0;i<=s;i++)up.push_back(up[i]);
    for(int i = 0;i<s;i++){
        int p = i+1;
        for(int j = i+1;j<s;j++){
            while(p<up.size()&&area(up[i],up[j],up[p])<=area(up[i],up[j],up[p+1])-eps)p++;
            ans = max(ans,area(up[i],up[j],up[p])/2);
        }
    }
    cout<<fixed<<setprecision(6)<<ans;
}