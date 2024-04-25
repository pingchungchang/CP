#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

#define fs first
#define sc second
#pragma GCC optimize("O3")
#define ll long long

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

const int mxn = 5050;
int n,m;

void solve(){
    cin>>m; 
    point s,e;
    cin>>s.x>>s.y>>e.x>>e.y;
    pair<point,point> arr[mxn];
    arr[0] = {s,point(s.x,e.y)};
    for(int i = 1;i<=n;i++){
        cin>>arr[i].fs.x>>arr[i].sc.x;
        arr[i].fs.y = s.y,arr[i].sc.y = e.y;
    }
    arr[n+1] = {point(e.x,s.y),e};
    int ans[mxn] = {};
    for(int i = 0;i<m;i++){
        point now;
        cin>>now.x>>now.y;
        for(int j = 1;j<=n+1;j++){
            int cnt = 0;
            point dir(arr[j].fs-arr[j].sc);
            if((dir^(arr[j].fs-now))<0)cnt++;
            if((dir^(arr[j].sc-now))<0)cnt++;
            if(cnt){
                ans[j-1] ++;
                break;
            }
            // if(j == n+1){
            //     cout<<"ERROR:"<<now.x<<' '<<now.y<<endl;exit(0);
            // }
            assert(j != n+1);
        }
    }
    for(int i = 0;i<=n;i++)cout<<i<<": "<<ans[i]<<'\n';
    cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n&&n!=0){solve();}
}
