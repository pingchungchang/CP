#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

struct pt{
    ll x,y;
    pt(){
        x = y = 0;
    }
    pt(ll a,ll b){
        x = a,y =b;
    }
    pt operator+(pt b)const{
        return pt(x+b.x,y+b.y);
    }
    pt operator-(pt b)const{
        return pt(x-b.x,y-b.y);
    }
    ll operator*(pt b)const{
        return x*b.x+y*b.y;
    }
    ll operator^(pt b)const{
        return x*b.y-y*b.x;
    }
};
bool onseg(pt a,pt b,pt tar){
    if(((a-tar)^(b-tar)) != 0LL)return false;
    else if((a-tar)*(b-tar)>0LL)return false;
    return true;
}
ll dir(pt a,pt b){
    if((a^b) > 0LL)return 1;
    else if((a^b) < 0LL)return -1;
    else return 0;
}
bool intersect(pt a,pt b,pt c,pt d){
    if(onseg(a,b,c)||onseg(a,b,d)||onseg(c,d,a)||onseg(c,d,b))return true;
    if(dir(a-c,d-c)*dir(b-c,d-c)<0&&dir(c-a,b-a)*dir(d-a,b-a)<0)return true;
    return false;
}
void solve(){
    pt a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    cout<<(intersect(a,b,c,d)?"YES\n":"NO\n");
    return;
}
int main(){
//	auto it = pt(0,1)^pt(1,1);
//	cout<<it<<endl;return 0;
//	cout<<it.x<<' '<<it.y<<endl;return 0;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
