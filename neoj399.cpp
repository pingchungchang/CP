#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct point{
    ll x,y;
    point(){x = y = 0;}
    point(ll a,ll b){x = a,y = b;}
    point operator+(point b)const{return point(x+b.x,y+b.y);}
    point operator-(point b)const{return point(x-b.x,y-b.y);}
    ll operator*(point b)const{return x*b.x+y*b.y;}
    ll operator^(point b)const{return x*b.y-y*b.x;}
    bool operator<(point b)const{return x == b.x?y<b.y:x<b.x;}
};
const int mxn = 1010;
unordered_map<ll,ll> mp;
point arr[mxn];


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
    }
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            mp[(arr[i]-arr[j])*(arr[i]-arr[j])]++;
        }
    }
    ll ans = 0;
    for(auto &i:mp)ans += i.second*(i.second-1)/2;
    cout<<ans<<endl;
}