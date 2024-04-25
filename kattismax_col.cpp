#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

struct point{
    ll x,y;
    point(){
        x = y = 0;
    }
    point(ll a,ll b){
        x = a,y = b;
    }
    point operator+(point b){
        return point(x+b.x,y+b.y);
    }
    point operator-(point b){
        return point(x-b.x,y-b.y);
    }
    ll operator^(point b){
        return x*b.y-y*b.x;
    }
    ll operator*(point b){
        return x*b.x+y*b.y;
    }
};
bool cmp(point &a,point &b){
    return (a^b) > 0;
}

const int mxn = 1010;
point arr[mxn];
int ans = 0;
int n;

void solve(int p){
    vector<point> up,down;
    int base = 0;
    for(int i = 0;i<n;i++){
        point tmp = arr[i]-arr[p];
        if(tmp.y==0){
            if(tmp.x == 0){
                base++;
                continue;
            }
            if(tmp.x>=0)up.push_back(tmp);
            else down.push_back(tmp);
        }
        else if(tmp.y>=0)up.push_back(tmp);
        else down.push_back(tmp);
    }
    sort(up.begin(),up.end(),cmp);
    ans = max(ans,base);
    sort(down.begin(),down.end(),cmp);
    int p1 = 0,p2 = 0,cnt = 0;
    for(int i = 0;i<up.size();i++){
        cnt = 0;
        if(p1<i)p1 = i;
        while(p1 != up.size()&&((up[i]^up[p1]) == 0))p1++,cnt++;
        while(p2 != down.size()&&((up[i]^down[p2])>0))p2++;
        while(p2 != down.size()&&((up[i]^down[p2]) == 0))p2++,cnt++;
        ans = max(ans,cnt+base);
        // cout<<i<<":"<<p1<<' '<<p2<<' '<<cnt<<endl;
    }
    // cout<<p<<':'<<ans<<endl;
    // cout<<"HI"<<endl;
    p1 = p2 = cnt = 0;
    for(int i = 0;i<down.size();i++){
        if(p1<i)p1 = i;
        cnt = 0;
        while(p1 != down.size()&&((down[i]^down[p1]) == 0))p1++,cnt++;
        while(p2 != up.size()&&((down[i]^up[p2])>0))p2++;
        while(p2 != up.size()&&((down[i]^up[p2]) == 0))p2++,cnt++;
        ans = max(ans,cnt+base);
    }
    return;
}
void solve1(){
    ans = 0;
    for(int i =0;i<n;i++)cin>>arr[i].x>>arr[i].y;
    for(int i = 0;i<n;i++)solve(i);
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n&&n!= 0)solve1();
}