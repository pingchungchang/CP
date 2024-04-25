#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf = 1e9+10;
struct pt{
    ll x,y;
    pt(){}
    pt(ll a,ll b){
        x = a,y =b;
    }
    pt operator+(pt b)const{
        return pt(x+b.x,y+b.y);
    }
    pt operator-(pt b){
        return pt(x-b.x,y-b.y);
    }
    ll operator*(pt b)const{
        return x*b.x+y*b.y;
    }
    ll operator^(pt b)const{
        return x*b.y-y*b.x;
    }
};
bool onseg(pt a,pt b,pt c){
    if(((c-a)^(c-b)) != 0)return false;
    if(((c-a)*(c-b))<=0)return true;
    return false;
}

ll dir(pt a,pt b){
    if((a^b)<0)return -1;
    else if((a^b)>0)return 1;
    else return 0;
}
ll banana(pt a,pt b,pt c,pt d){
    if(onseg(a,b,c)||onseg(a,b,d)||onseg(c,d,a)||onseg(c,d,b))return 2;
    if(dir(a-c,d-c)*dir(b-c,d-c)<=0&&dir(c-a,b-a)*dir(d-a,b-a)<=0)return 1;
    else return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    pt a[n+1],b[m];
    for(int i = 0;i<n;i++)cin>>a[i].x>>a[i].y;
    a[n] = a[0];
    for(auto &i:b)cin>>i.x>>i.y;
    for(auto &i:b){
        bool done = false;
        for(int j= 0;j<n;j++){
            if(onseg(a[j],a[j+1],i)){
                cout<<"BOUNDARY\n";
                done = true;
                break;
            }
        }
        if(done)continue;
        ll cnt = 0;
        for(int j= 0;j<n;j++){
            if(banana(a[j],a[j+1],i,pt(inf,i.y+1)) == 1)cnt++;
        }
        if(cnt&1){
            cout<<"INSIDE\n";
        }
        else cout<<"OUTSIDE\n";
    }
    return 0;
}