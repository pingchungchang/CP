#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define pll pair<ll,ll>
#define ll long long
#define fs first
#define sc second

const ld eps = 1e-6;
ld dist(pll a,pll b){
    return sqrt((a.fs-b.fs)*(a.fs-b.fs)+(a.sc-b.sc)*(a.sc-b.sc));
}
ld dot(pll a,pll b){
    return a.fs*b.fs+a.sc*b.sc;
}
ld cross(pll a,pll b){
    return a.fs*b.sc-b.fs*a.sc;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pll now;
    int n;
    cin>>now.fs>>now.sc>>n;
    pll pre;
    cin>>pre.fs>>pre.sc;
    ld ans = dist(pre,now);
    pll tmp;
    while(cin>>tmp.fs>>tmp.sc){
        pll d1 = {tmp.fs-now.fs,tmp.sc-now.sc};
        pll d2 = {pre.fs-now.fs,pre.sc-now.sc};
        pll hor = {pre.sc-tmp.sc,tmp.fs-pre.fs};
        bool flag = false;
        // cout<<d1.fs<<' '<<d1.sc<<','<<d2.fs<<' '<<d2.sc<<'\n';
        if(cross(d1,hor)==0||cross(d2,hor)==0)flag = true;
        else if(cross(d1,hor)/abs(cross(d1,hor))*cross(d2,hor)<0)flag = true;
        // cout<<flag;
        if(flag){
            ans = min(ans,(ld)abs(cross(d1,d2))/dist(tmp,pre));
        }
        else{
            ans = min({ans,dist(now,tmp),dist(now,pre)});
        }
        pre = tmp;
    }
    cout<<fixed<<setprecision(10)<<ans;
}