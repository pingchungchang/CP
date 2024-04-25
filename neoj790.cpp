#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll col = 0;
struct point{
    ll x,y;
    point(){x = y = 0;}
    point(ll a,ll b):x(a),y(b){}
    point operator+(point b)const{return point(x+b.x,y+b.y);}
    point operator-(point b)const{return point(x-b.x,y-b.y);}
    ll operator*(point b)const{return x*b.x+y*b.y;}
    ll operator^(point b)const{return x*b.y-y*b.x;}
    bool operator<(point b)const{return x == b.x?y<b.y:x<b.x;}
};

bool cmp(point &a,point &b){
    return (a^b)>0;
}
ostream& operator<<(ostream &out,point p){
    out<<p.x<<','<<p.y;
    return out;
}
const int mxn = 3030;
point arr[mxn];
ll n;
unordered_map<ll,ll> mp;

void solve(int p){
    vector<point> up,down;
    for(int i = 0;i<n;i++){
        if(p == i)continue;
        auto tmp = arr[p]-arr[i];
        if(tmp.y== 0){
            if(tmp.x>=0)up.push_back(tmp);
            else down.push_back(tmp);
        }
        else if(tmp.y>0)up.push_back(tmp);
        else down.push_back(tmp);
    }
    sort(up.begin(),up.end(),cmp);
    sort(down.begin(),down.end(),cmp);
    ll cnt = 0;
    int p1=0,p2 = 0,p3 = 0,p4 = 0;
    // cout<<p<<":"<<endl;
    // for(auto &i:up)cout<<i<<' ';cout<<endl;
    // for(auto &i:down)cout<<i<<' ';cout<<endl;
    for(int i = 0;i<up.size();i++){
        cnt = 0;
        while(p1<up.size()&&(up[i]^up[p1])<0)p1++;
        p2 = max(p2,p1);
        while(p2<up.size()&&(up[i]^up[p2]) == 0)p2++;
        while(p3<down.size()&&(down[p3]^up[i])<0)p3++;
        p4 = max(p3,p4);
        while(p4<down.size()&&(down[p4]^up[i]) == 0)p4++;
        cnt = p2-p1+p4-p3;
        // cout<<up[i]<<":"<<p1<<' '<<p2<<' '<<p3<<' '<<p4<<endl;
        // cout<<p<<":"<<up[i].x<<' '<<up[i].y<<' '<<up[p1]<<' '<<up[p2]<<' '<<down[p3]<<' '<<down[p4]<<' '<<cnt<<endl;
        mp[cnt+1]++;
    }
    p1 = p2 = p3 = p4 = 0;
    for(int i = 0;i<down.size();i++){
        cnt = 0;
        while(p1<down.size()&&(down[i]^down[p1])<0)p1++;
        p2 = max(p2,p1);
        while(p2<down.size()&&(down[i]^down[p2]) == 0)p2++;
        while(p3<up.size()&&(up[p3]^down[i])<0)p3++;
        p4 = max(p4,p3);
        while(p4<up.size()&&(up[p4]^down[i]) == 0)p4++;
        cnt = p2-p1+p4-p3;
        // cout<<down[i]<<":"<<p1<<' '<<p2<<' '<<p3<<' '<<p4<<endl;
        // cout<<p<<":"<<down[i].x<<' '<<down[i].y<<' '<<down[p1]<<' '<<down[p2]<<' '<<up[p3]<<' '<<up[p4]<<' '<<cnt<<endl;
        mp[cnt+1]++;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i= 0;i<n;i++)cin>>arr[i].x>>arr[i].y;
    for(int i = 0;i<n;i++)solve(i);
    for(auto &i:mp){
        auto c = i.second;
        i.second = i.second/i.first/(i.first-1);
        col += (i.first)*(i.first-1)*(i.first-2)/6*i.second;
    }
    cout<<n*(n-1)*(n-2)/6-col<<endl;
}
/*


*/