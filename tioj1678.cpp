#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct point{
    ll x,y;
    point(ll a,ll b):x(a),y(b){}
    point(){x = y = 0;}
    point operator+(point b)const{return point(x+b.x,y+b.y);}
    point operator-(point b)const{return point(x-b.x,y-b.y);}
    ll operator^(point b)const{return x*b.y-y*b.x;}
    bool operator<(point b)const{return x==b.x?y<b.y:x<b.x;}
};

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,A;
    cin>>n>>A;
    A *= 2;
    point arr[n];
    ll dif = 0;
    for(auto &i:arr)cin>>i.x>>i.y;
    for(int i = 1;i<n;i++)dif += (arr[i]^arr[i-1]);
    dif += (arr[0]^arr[n-1]);
    dif = abs(dif);
    sort(arr,arr+n);
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
    up.pop_back();
    for(auto &i:down)up.push_back(i);
    int total = 0;
    for(int i = 1;i<up.size();i++)total += (up[i-1]^up[i]);
    // cout<<total<<' '<<dif<<endl;
    total = abs(total);
    total -= dif;
    cout<<(total+A-1)/A;
}